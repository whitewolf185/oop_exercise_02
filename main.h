#ifndef OOP_EXERCISE_02_MAIN_H
#define OOP_EXERCISE_02_MAIN_H

#include <iostream>
#include <cmath>
#include <string>


struct coord{
    double x, y;
};


//-------------------start of class--------------------
class Rectangle{

private:
    coord p1{}, p2{};
    bool is_seg;

    void enter_sides(coord P1, coord P2){
        p1.x = P1.x;
        p1.y = P1.y;
        p2.x = P2.x;
        p2.y = P2.y;

        if(p1.x > p2.x && p1.y > p2.y){
            std::cout << "you entered wrong x and y";
            exit(1);
        }

        if(get_area() == 0){
            is_seg = true;
        }
        else{
            is_seg = false;
        }
    }

//----------end private-------------

public:

    Rectangle(){
        p1.x = 0;
        p1.y = 0;
        p2.x = 0;
        p2.y = 0;
        is_seg = true;
    }

    Rectangle(double x_1,double y_1,double x_2,double y_2) {
        p1.x = x_1;
        p1.y = y_1;
        p2.x = x_2;
        p2.y = y_2;

        if(p1.x > p2.x && p1.y > p2.y){
            std::cout << "you entered wrong x and y";
            exit(1);
        }

        if(get_area() == 0){
            is_seg = true;
        }
        else{
            is_seg = false;
        }
    }

    void set_sides(){
        std::cout << "Enter your points.\n"
                     "The First one is left-down edge. The Second one is right-up edge.\n" << std::endl;
        coord p_1, p_2;
        std::cin >> p_1.x >> p_1.y >> p_2.x >> p_2.y;

        enter_sides(p_1,p_2);
    }

    Rectangle(coord p_1, coord p_2): p1(p_1), p2(p_2){
        if(get_area() == 0){
            is_seg = true;
        }
        else{
            is_seg = false;
        }

        if(p1.x > p2.x && p1.y > p2.y){
            std::cout << "you entered wrong x and y";
            exit(1);
        }
    }

    double get_perimeter() const {
        return 2 * (p2.x - p1.x + p2.y - p1.y);
    }

    double get_perimeter(Rectangle tmp_rec) const {
        return 2 * (tmp_rec.p2.x - tmp_rec.p1.x + tmp_rec.p2.y - tmp_rec.p1.y);
    }

    double get_area() const {
        return (p2.x - p1.x) * (p2.y - p1.y);
    }

    double get_area(Rectangle tmp_rec) const {
        return (tmp_rec.p2.x - tmp_rec.p1.x) * (tmp_rec.p2.y - tmp_rec.p1.y);
    }

    void shift_x(double sh_x){
        p1.x += sh_x;
        p2.x += sh_x;
    }

    void shift_y(double sh_y){
        p1.y += sh_y;
        p2.y += sh_y;
    }

    void difference_perim(Rectangle tmp_rec){

    }


    Rectangle Lil_Rect(Rectangle a){
        Rectangle LilBro;

        if( (p1.y > a.p2.y) || (a.p1.y > p2.y) ||
        (p1.y> a.p2.x) || (a.p1.x < p2.y))
        {
            return LilBro;
        }

        /*if(a.is_seg || this->is_seg){
            return *this;
        }*/

        LilBro.p1.y = fmax(a.p1.y,p1.y);
        LilBro.p2.x = fmin(a.p2.x,p2.x);
        LilBro.p1.y = fmax(a.p1.y,p1.y);
        LilBro.p2.y = fmin(a.p2.y,p2.y);

        LilBro.is_seg = false;

        return LilBro;
    };

    Rectangle Big_Rect(Rectangle a){
        Rectangle BigBro;

        BigBro.p2.y = fmax(a.p2.y,p2.y);
        BigBro.p1.y = fmin(a.p1.y,p1.y);
        BigBro.p1.x = fmax(fmax(p1.x,p2.x),fmax(a.p1.x,a.p2.x));
        BigBro.p2.x = fmin(fmin(p1.x,p2.x),fmin(a.p1.x,a.p2.x));

        BigBro.is_seg = false;

        return BigBro;
    };

    //prefix
    Rectangle& operator++(){

        p2.x += 1;
        p2.y += 1;

        return *this;
    }

    //postfix
    Rectangle operator++(int){
        Rectangle result = *this;
        p2.x += 1;
        p2.y += 1;

        return result;
    }

    //prefix
    Rectangle& operator--(){
        p2.x -= 1;
        p2.y -= 1;

        return *this;
    }

    //postfix
    Rectangle operator--(int){
        Rectangle result = *this;


        p2.x -= 1;
        p2.y -= 1;

        return result;
    }

    bool is_Seg() const{
        return is_seg;
    }

    [[nodiscard]] double get_width()const{
        return p2.x - p1.x;
    }

    [[nodiscard]] double get_height() const{
        return p2.y - p1.y;
    }


};

//----------------end of class--------------------------

Rectangle operator"" _rec(const char *str, size_t n){
    double xy[4];

    std::string s(str);
    s += ',';// просто чтобы не писать лишний код
    short count = 0; double last = 0;
    for (int i = 0; i <= n; ++i) {
        if(s[i] == ',' && count < 5){
            try {
                xy[count] = std::stod(s.substr(last, i - last + 1));
            } catch (std::invalid_argument) {
                std::cout << "you do something wrong\n";
            }
            last = i + 1;
            ++count;
        }
    }

    return Rectangle(xy[0],xy[1],xy[2],xy[3]);
}


bool operator<(const Rectangle& lhs,const Rectangle& rhs){
    return lhs.get_area() < rhs.get_area();
}

bool operator>(const Rectangle &lhs, const Rectangle &rhs){
    return lhs.get_area() > rhs.get_area();
}

bool operator==(const Rectangle &lhs, const Rectangle &rhs){
    return lhs.get_area() == rhs.get_area();
}



#endif //OOP_EXERCISE_02_MAIN_H