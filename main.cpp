/*Волков Матвей Андреевич
 *
 * Разработать класс Rectangle, представляющий собой прямоугольник со сторонами, параллельными осям координат.
 * Поля – координаты левого нижнего и правого верхнего угла. Требуется реализовать следующие методы: вычисление площади
 * и периметра, перемещения вдоль осей, изменение размеров, сравнение по площади и по периметру. Реализовать метод
 * получения прямоугольника, представляющего общую часть (пересечение) двух прямоугольников. Реализовать метод
 * объединения двух прямоугольников: наименьший прямоугольник, включающего оба заданных прямоугольника.
 *
Необходимо реализовать:
- операцию приведения к типу double, вычисляющую площадь прямоугольника;
- операцию префиксного и постфиксного инкремента, увеличивающую одновременно размеры сторон прямоугольника.
- операции сравнения (больше, меньше, равно);
Необходимо реализовать пользовательский литерал для работы с константами типа Rectangle.
*/

#include "main.h"

int main(){
    Rectangle rec1, rec2;
    Rectangle lit_rec = "1,1,2,f"_rec;

    lit_rec.show_W_H();
    lit_rec.show_perimeter();

    lit_rec = "1,1,2,2"_rec;

    lit_rec.show_W_H();
    lit_rec.show_perimeter();

    rec1.set_sides(); rec2.set_sides();
    rec1.show_perim_differ(rec2);
    if(rec1 < rec2){
        std::cout << "rec2 have bigger area then rec1" << std::endl;
    }
    if(rec1 > rec2){
        std::cout << "rec1 have bigger area then rec2" << std::endl;
    }
    if (rec1 == rec2){
        std::cout << "rec1 and rec2 have equal area" << std::endl;
    }

    std::cout << "lit_rec" << std::endl;

    lit_rec.show_W_H();
    lit_rec.show_perimeter();
    lit_rec++;
    lit_rec.show_perimeter();
    lit_rec.show_W_H();
    std::cout << "lit_rec shifting" << std::endl;
    lit_rec.shift_x(2);
    lit_rec.show_coordinates();
    lit_rec.shift_y(-1);
    lit_rec.show_coordinates();

    std::cout << "\nmerging" << std::endl;

    Rectangle rec1_pl_lit = lit_rec.Big_Rect(rec1);
    rec1_pl_lit.show_coordinates();
    rec1_pl_lit.show_W_H();

    std::cout << "\nseparation" << std::endl;

    Rectangle rec2_sb_lit = rec2.Lil_Rect(lit_rec);
    rec2_sb_lit.show_coordinates();
    rec2_sb_lit.show_W_H();


    return 0;
}