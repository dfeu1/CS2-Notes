

int main() {

    rectangle s1(5, 4);
    s1.move(3, 7);
    s1.draw();

    square s2(4);
    s2.move(6, 8);
    s2.draw();

    shape* tbl[4];

    tbl[0] = new square(2); 
    tbl[1] = new square(5);
    tbl[2] = new rectangle(4, 3);
    tbl[3] = new circle(4);

    std::cout << "The Shapes in the ";
    int n = 0;
    for (int i = 0; i < 4; ++i) {
        tbl[i] -> draw();
        if (tbl[i]->isSqaure()) n++;
    }

    std::cout << "number of swaures: " << n << std::endl;
    
    for (int i = 0; i < 4; ++i) {
        delete tbl[i];
    }

}