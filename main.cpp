#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "base64.h"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <iomanip>

using namespace std;

/**
 *  cryptopals.com
 *  Set 1 - Challenge 1: Convert hex to base64
 */



/** \brief File to vector<string>.
 *
 * \param	filename The name of the file to read
 * \return	Return value.
 *
 * Reads the contents of a text file into a vector of strings.
 */
vector<string> readFromFile(const char* filename)
{
    string line;
    vector<string> fileLines = vector<string>();

    ifstream myfile(filename, std::ifstream::in);
    if(myfile.is_open())
    {
        while(getline(myfile,line))
        {
            fileLines.push_back(line);
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    return fileLines;
}

/** \brief Hex char to int converter.
 *
 * \param	ch The hexadecimal character.
 * \return	Returs the parameter's integer value. Returns -1 in case of error. (review later)
 *
 * Returns the int value of a single hexadecimal char.
 */
int HexCharToInt(char ch)
{
    if(isdigit(ch))
        return ch - '0';
    if(tolower(ch) >= 'a' && tolower(ch) <= 'f')
        return ch - 'a' + 10;
    return -1;
}

/** \brief Hex string to byte array.
 *
 * \param	*dest Target array of bytes.
 * \param	*source Source string.
 * \param	bytes_n Number of the bytes.
 * \return	Return value.
 *
 * Converts a hexadecimal string to an array of bytes.
 */
void HexStringToByteArray(unsigned char *dest, const char *source, int bytes_n)
{
    for(bytes_n--; bytes_n >= 0; bytes_n--)
        dest[bytes_n] = 16 * HexCharToInt(source[bytes_n*2]) + HexCharToInt(source[bytes_n*2 + 1]);
}


/** \brief XOR for two byte arrays.
 *
 * \param	*a array of bytes.
 * \param	*b array of bytes.
 * \param	bytes_n Number of the bytes.
 * \return	Returns the result of the xor of the two byte arrays.
 *
 * Calculates the XOR of two byte arrays.
 */
unsigned char * xor2strings(unsigned char *a, unsigned char *b, int bytes_n)
{
    unsigned char *result = new unsigned char(bytes_n);
    for (int i=0; i<bytes_n; i++)
        result[i] = (unsigned char)(a[i] ^ b[i]);
    return result;
}




int main()
{
    //S1C1
    /*
    std::vector<string> inputFile = readFromFile("a.txt");
    string inputString = inputFile.at(0);

    cout << inputString << endl;
    cout << inputString.length() << endl;

    int byteArrayLength = inputString.length()/2;
    unsigned char *byteArray = new unsigned char(byteArrayLength);
    HexStringToByteArray(byteArray, inputString.c_str(), byteArrayLength);
    std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(byteArray), byteArrayLength);
    std::cout << "encoded: " << encoded << std::endl;
*/
/*
      const std::string s = "ADP GmbH\nAnalyse Design & Programmierung\nGesellschaft mit beschränkter Haftung" ;
      std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
      std::string decoded = base64_decode(encoded);
      std::cout << "encoded: " << encoded << std::endl;
      std::cout << "decoded: " << decoded << std::endl;
*/

//SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t
//SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t


    std::vector<string> inputFileS1C2 = readFromFile("s1c2.txt");
    string inputStringA = inputFileS1C2.at(0);
    string inputStringB = inputFileS1C2.at(1);

    cout << inputStringA << endl;
    cout << inputStringB << endl;


    int byteArrayLengthS1C2 = inputStringA.length()/2;
    unsigned char *byteArrayA = new unsigned char[byteArrayLengthS1C2];
    unsigned char *byteArrayB = new unsigned char[byteArrayLengthS1C2];

    HexStringToByteArray(byteArrayA, inputStringA.c_str(), byteArrayLengthS1C2);
    HexStringToByteArray(byteArrayB, inputStringB.c_str(), byteArrayLengthS1C2);




/*
    unsigned char * a = new unsigned char(6);
    unsigned char * b = new unsigned char(6);

    a[0] = 77;
    a[1] = 77;
    a[2] = 77;
    a[3] = 77;
    a[4] = 77;
    a[5] = 77;
*/
    cout << byteArrayLengthS1C2 << endl;
    const unsigned char * resultsS1C2 = xor2strings(byteArrayA, byteArrayB, byteArrayLengthS1C2);

    // TODO: nem ez kell, hanem byte -> hex
    //std::string resultsEncodedS1C2 = base64_encode(reinterpret_cast<const unsigned char*>(resultsS1C2), byteArrayLengthS1C2);

    //cout << resultsEncodedS1C2 << endl;



    for (int i=0; i<byteArrayLengthS1C2; i++)
    {
        std::stringstream csocs;
        csocs << std::hex << (int)resultsS1C2[i];
        std::cout << csocs.str();
    }
    //std::cout << csocs.str() << '\n';


    //int n = 90;
    //std::stringstream anyad;
    //anyad << std::hex << n;
    //std::cout << anyad.str() << '\n';


    //746865206b696420646f6e277420706c6179
    //746865206b696420646f6e277420706c6179



    delete [] byteArrayA;
    delete [] byteArrayB;
    delete [] resultsS1C2;

    return 0;
}







