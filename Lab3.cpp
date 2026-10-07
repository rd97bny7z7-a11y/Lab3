/*
 * Author: Ivan
 * Course: CSC-142 / CS-162 (Computer Science I)
 * Lab Name: Lab 3 User and File I/O
 * Description: Program that reads 4 integers from a file "inMeanStd.dat"
 *              or user input, calculates the mean and population standard 
 *              deviation, and writes the output to both the console 
 *              and an output file "outMeanStd.dat".
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Declaracion de variables para los 4 enteros
    int num1, num2, num3, num4;
    
    // Intentar abrir el archivo de entrada
    ifstream inFile;
    inFile.open("inMeanStd.dat");
    
    // Si el archivo existe y abre bien, leer datos del archivo
    if (inFile.is_open()) {
        inFile >> num1 >> num2 >> num3 >> num4;
        inFile.close();
    } else {
        // Si no existe el archivo, pedir datos al usuario por consola
        cout << "Enter four integers separated by spaces: ";
        cin >> num1 >> num2 >> num3 >> num4;
    }
    
    // Calculo de la media (mean)
    double mean = (num1 + num2 + num3 + num4) / 4.0;
    
    // Calculo de la desviacion estandar poblacional (population standard deviation)
    double variance = (pow(num1 - mean, 2) + 
                       pow(num2 - mean, 2) + 
                       pow(num3 - mean, 2) + 
                       pow(num4 - mean, 2)) / 4.0;
                       
    double stdDev = sqrt(variance);
    
    // 1. Mostrar resultados en la consola
    cout << fixed << setprecision(2);
    cout << "\n--- RESULTS ---" << endl;
    cout << "Input Numbers: " << num1 << " " << num2 << " " << num3 << " " << num4 << endl;
    cout << "Mean: " << mean << endl;
    cout << "Population Standard Deviation: " << stdDev << endl;
    
    // 2. Guardar resultados en el archivo "outMeanStd.dat"
    ofstream outFile;
    outFile.open("outMeanStd.dat");
    
    if (outFile.is_open()) {
        outFile << fixed << setprecision(2);
        outFile << "Input Numbers: " << num1 << " " << num2 << " " << num3 << " " << num4 << endl;
        outFile << "Mean: " << mean << endl;
        outFile << "Population Standard Deviation: " << stdDev << endl;
        outFile.close();
        cout << "\nResults successfully written to outMeanStd.dat" << endl;
    } else {
        cout << "Error opening output file." << endl;
    }

    return 0;
}