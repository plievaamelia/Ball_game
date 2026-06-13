//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int main() {
//    const int N = 100000;
//    const int chainLength = 100;
//    const int chainColor = 5;
//    int pos = (N - chainLength) / 2;
//
//    ofstream fout("Balls_colors.txt");
//    if (!fout) {
//        cerr << "Ошибка создания файла!" << endl;
//        return 1;
//    }
//
//    fout << N << endl;
//
//    for (int i = 0; i < N; ++i) {
//        if (i >= pos && i < pos + chainLength) {
//            fout << chainColor;
//        }
//        else {
//            int color = (i % 10);
//            if (color == chainColor) color = 0;
//            fout << color;
//        }
//        if (i != N - 1) fout << " ";
//    }
//
//    fout.close();
//    cout << "Файл input.txt сгенерирован. Количество шариков: " << N
//        << ", цепочка из " << chainLength << " шариков цвета " << chainColor
//        << " в позиции " << pos << " (ответ = " << chainLength << ")" << endl;
//    return 0;
//}