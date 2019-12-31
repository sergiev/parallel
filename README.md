# openMP use cases
0. Численное интегрирование
1. Поиск максимального значения среди минимальных элементов строк матрицы **(non-MP)**
2. Умножение матриц
3. Умножение матрицы на вектор следующими способами:

    - разделение данных по строкам
    - разделение данных по столбцам
    - блочное разделение данных

4. Умножение матриц:

- применяя ленточное разделение данных;
- применяя блочное разделение данных.

TODO: Для 3 и 4 программ провести сравнение времени выполнения последовательной программы относительно указанных вариантов параллельной программы на различном количестве нитей. Размер исходных данных переменный. Результаты измерений представить в виде таблицы или графика.

5. Поиск шаблона в файле. Программа по поиску подстроки в строке с использованием параллельных директив.
