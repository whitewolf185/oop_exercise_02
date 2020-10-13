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

    double difference_perim(Rectangle tmp_rec) const {
        return fabs(tmp_rec.get_perimeter() - this->get_perimeter());
    }

    void enter_sides(coord P1, coord P2){
        p1.x = P1.x;
        p1.y = P1.y;
        p2.x = P2.x;
        p2.y = P2.y;

        if(p1.x > p2.x || p1.y > p2.y){
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

        if(p1.x > p2.x || p1.y > p2.y){
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

        if(p1.x > p2.x || p1.y > p2.y){
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

    constexpr void shift_x(double sh_x){
        p1.x += sh_x;
        p2.x += sh_x;
    }

    constexpr void shift_y(double sh_y){
        p1.y += sh_y;
        p2.y += sh_y;
    }

    void show_perim_differ (Rectangle tmp_rec) const{
        std::cout << "Perimeter difference is " << difference_perim(tmp_rec) << std::endl;
    }

    void show_W_H() const {
        std::cout << "width is " << this->get_width() << " height is " << this->get_height() << std::endl;
    }

    Rectangle Lil_Rect(Rectangle tmp_rec){
        Rectangle LilBro;

        if((p1.y > tmp_rec.p2.y) || (tmp_rec.p1.y > p2.y) ||
           (p1.x > tmp_rec.p2.x) || (tmp_rec.p1.x < p2.x))
        {
            return LilBro;
        }

        LilBro.p1.y = fmax(tmp_rec.p1.y, p1.y);
        LilBro.p2.x = fmin(tmp_rec.p2.x, p2.x);
        LilBro.p1.y = fmax(tmp_rec.p1.y, p1.y);
        LilBro.p2.y = fmin(tmp_rec.p2.y, p2.y);

        LilBro.is_seg = get_area() == 0;;

        return LilBro;
    };

    Rectangle Big_Rect(Rectangle tmp_rec){
        Rectangle BigBro;

        BigBro.p2.y = fmax(tmp_rec.p2.y, p2.y);
        BigBro.p1.y = fmin(tmp_rec.p1.y, p1.y);
        BigBro.p1.x = fmin(fmax(p1.x,p2.x),fmin(tmp_rec.p1.x, tmp_rec.p2.x));
        BigBro.p2.x = fmax(fmin(p1.x,p2.x),fmax(tmp_rec.p1.x, tmp_rec.p2.x));
        BigBro.is_seg = get_area() == 0;

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
        if(this->get_height() - 1 > 0 && this->get_width() - 1 > 0) {
            p2.x -= 1;
            p2.y -= 1;
        }
        else{
            std::cout << "I cant" << std::endl;
        }
        return *this;
    }

    //postfix
    Rectangle operator--(int){
        Rectangle result = *this;
        if(this->get_height() - 1 > 0 && this->get_width() - 1 > 0) {
            p2.x -= 1;
            p2.y -= 1;
        }
        else{
            std::cout << "I cant" << std::endl;
        }
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


    void show_coordinates() const {
        std::cout << "Point 1 is " << p1.x << ' ' << p1.y << '\n' <<
                    "Point 2 is " << p2.x << ' ' << p2.y << std::endl;
    }

    void show_perimeter() const {
        std::cout << "perimeter is " << this->get_perimeter() << std::endl;
    }

    void show_area() const {
        std::cout << "area is " << this->get_area() << std::endl;
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
            }
            catch (const std::invalid_argument&) {
                std::cout << "You entered wrong arguments!\n"
                             "The obj will be empty" << std::endl;
                xy[0] = 0;
                xy[1] = 0;
                xy[2] = 0;
                xy[3] = 0;
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