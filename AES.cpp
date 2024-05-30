#include <iostream>
#include <cmath>
#include <string>
#include <bitset>
#include <sstream>
#include <cstring>

using namespace std;

int num_of_zeros;
string DecimalToBinary(int dec)
{
    if (dec < 1)
        return "0";
    string binStr = "";
    while (dec > 0)
    {
        binStr = binStr.insert(0, string(1, (char)((dec % 2) + 48)));
        dec /= 2;
    }
    return binStr;
}

string ASCIIToBinary(string str)
{
    string bin = "";
    int strLength = str.length();

    for (int i = 0; i < strLength; ++i)
    {
        string cBin = DecimalToBinary(str[i]);
        int cBinLength = cBin.length();

        if (cBinLength < 8)
        {
            for (size_t i = 0; i < (8 - cBinLength); i++)
                cBin = cBin.insert(0, "0");
        }

        bin += cBin;
    }
    return bin;
}

string BinaryToASCII(string binaryString)
{
    string text = "";
    stringstream sstream(binaryString);
    while (sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        text += char(bits.to_ulong());
    }
    return text;
}

string HexToBin(string hexdec)
{
    long int i = 0;
    string bin = "";
    while (hexdec[i])
    {
        switch (hexdec[i])
        {
        case '0':
            bin += "0000";
            break;
        case '1':
            bin += "0001";
            break;
        case '2':
            bin += "0010";
            break;
        case '3':
            bin += "0011";
            break;
        case '4':
            bin += "0100";
            break;
        case '5':
            bin += "0101";
            break;
        case '6':
            bin += "0110";
            break;
        case '7':
            bin += "0111";
            break;
        case '8':
            bin += "1000";
            break;
        case '9':
            bin += "1001";
            break;
        case 'A':
        case 'a':
            bin += "1010";
            break;
        case 'B':
        case 'b':
            bin += "1011";
            break;
        case 'C':
        case 'c':
            bin += "1100";
            break;
        case 'D':
        case 'd':
            bin += "1101";
            break;
        case 'E':
        case 'e':
            bin += "1110";
            break;
        case 'F':
        case 'f':
            bin += "1111";
            break;
        default:
            break;
        }
        i++;
    }
    return bin;
}

string BinToHex(const string& s)
{
    string out;
    for (int i = 0; i < s.size(); i += 4)
    {
        int8_t n = 0;
        for (int j = i; j < i + 4; ++j)
        {
            n <<= 1;
            if (s[j] == '1')
                n |= 1;
        }

        if (n <= 9)
            out.push_back('0' + n);
        else
            out.push_back('A' + n - 10);
    }

    return out;
}

int BinaryToDecimal(string binaryString)
{
    int value = 0;
    int indexCounter = 0;
    for (int i = binaryString.length() - 1; i >= 0; i--)
    {

        if (binaryString[i] == '1')
        {
            value += pow(2, indexCounter);
        }
        indexCounter++;
    }
    return value;
}

string xor_(string a, string b)
{
    string result = "";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])
        {
            result += "0";
        }
        else
        {
            result += "1";
        }
    }
    return result;
}



string SBox[16][16] =
{
    "63", "7C", "77", "7B", "F2", "6B", "6F", "C5", "30", "01", "67", "2B", "FE", "D7", "AB", "76",
    "CA", "82", "C9", "7D", "FA", "59", "47", "F0", "AD", "D4", "A2", "AF", "9C", "A4", "72", "C0",
    "B7", "FD", "93", "26", "36", "3F", "F7", "CC", "34", "A5", "E5", "F1", "71", "D8", "31", "15",
    "04", "C7", "23", "C3", "18", "96", "05", "9A", "07", "12", "80", "E2", "EB", "27", "B2", "75",
    "09", "83", "2C", "1A", "1B", "6E", "5A", "A0", "52", "3B", "D6", "B3", "29", "E3", "2F", "84",
    "53", "D1", "00", "ED", "20", "FC", "B1", "5B", "6A", "CB", "BE", "39", "4A", "4C", "58", "CF",
    "D0", "EF", "AA", "FB", "43", "4D", "33", "85", "45", "F9", "02", "7F", "50", "3C", "9F", "A8",
    "51", "A3", "40", "8F", "92", "9D", "38", "F5", "BC", "B6", "DA", "21", "10", "FF", "F3", "D2",
    "CD", "0C", "13", "EC", "5F", "97", "44", "17", "C4", "A7", "7E", "3D", "64", "5D", "19", "73",
    "60", "81", "4F", "DC", "22", "2A", "90", "88", "46", "EE", "B8", "14", "DE", "5E", "0B", "DB",
    "E0", "32", "3A", "0A", "49", "06", "24", "5C", "C2", "D3", "AC", "62", "91", "95", "E4", "79",
    "E7", "C8", "37", "6D", "8D", "D5", "4E", "A9", "6C", "56", "F4", "EA", "65", "7A", "AE", "08",
    "BA", "78", "25", "2E", "1C", "A6", "B4 ", "C6", "E8", "DD", "74", "1F", "4B", "BD", "8B", "8A",
    "70", "3E", "B5", "66", "48", "03", "F6", "0E", "61", "35", "57", "B9", "86", "C1", "1D", "9E",
    "E1", "F8", "98", "11", "69", "D9", "8E", "94", "9B", "1E", "87", "E9", "CE", "55", "28", "DF",
    "8C", "A1", "89", "0D", "BF", "E6", "42", "68", "41", "99", "2D", "0F"," B0", "54", "BB", "16"
};

string ISBox[16][16] =
{
    "52", "09", "6A", "D5", "30", "36", "A5", "38", "BF", "40", "A3", "9E", "81", "F3", "D7", "FB",
    "7C", "E3", "39", "82", "9B", "2F", "FF", "87", "34", "8E", "43", "44", "C4", "DE", "E9", "CB",
    "54", "7B", "94", "32", "A6", "C2", "23", "3D", "EE", "4C", "95", "0B", "42", "FA", "C3", "4E",
    "08", "2E", "A1", "66", "28", "D9", "24", "B2", "76", "5B", "A2", "49", "6D", "8B", "D1", "25",
    "72", "F8", "F6", "64", "86", "68", "98", "16", "D4", "A4", "5C", "CC", "5D", "65", "B6", "92",
    "6C", "70", "48", "50", "FD", "ED", "B9", "DA", "5E", "15", "46", "57", "A7", "8D", "9D", "84",
    "90", "D8", "AB", "00", "8C", "BC", "D3", "0A", "F7", "E4", "58", "05", "B8", "B3", "45", "06",
    "D0", "2C", "1E", "8F", "CA", "3F", "0F", "02", "C1", "AF", "BD", "03", "01", "13", "8A", "6B",
    "3A", "91", "11", "41", "4F", "67", "DC", "EA", "97", "F2", "CF", "CE", "F0", "B4", "E6", "73",
    "96", "AC", "74", "22", "E7", "AD", "35", "85", "E2", "F9", "37", "E8", "1C", "75", "DF", "6E",
    "47", "F1", "1A", "71", "1D", "29", "C5", "89", "6F", "B7", "62", "0E", "AA", "18", "BE", "1B",
    "FC", "56", "3E", "4B", "C6", "D2", "79", "20", "9A", "DB", "C0", "FE", "78", "CD", "5A", "F4",
    "1F", "DD", "A8", "33", "88", "07", "C7", "31", "B1", "12", "10", "59", "27", "80", "EC", "5F",
    "60", "51", "7F", "A9", "19", "B5", "4A", "0D", "2D", "E5", "7A", "9F", "93", "C9", "9C", "eF",
    "A0", "E0", "3B", "4D", "AE", "2A", "F5", "B0", "C8", "EB", "BB", "3C", "83", "53", "99", "61",
    "17", "2B", "04", "7E", "BA", "77", "D6", "26", "E1", "69", "14", "63", "55", "21", "0C", "7D"
};

string rc[10] =
{
    "00000001",
    "00000010",
    "00000100",
    "00001000",
    "00010000",
    "00100000",
    "01000000",
    "10000000",
    "00011011",
    "00110110"
};

string g_function(string word, int round_in)
{
    string rotWord = word.substr(8, 24) + word.substr(0, 8);
    string new_word = "";
    int col[4];
    int row[4];

    for (int i = 0; i < 4; i++)
    {
        row[i] = BinaryToDecimal(rotWord.substr(i * 8, 4));
        col[i] = BinaryToDecimal(rotWord.substr((i * 8) + 4, 4));
        if (i == 0)
        {
            new_word += xor_(HexToBin(SBox[row[i]][col[i]]), rc[round_in]);

        }
        else
        {
            new_word += HexToBin(SBox[row[i]][col[i]]);
        }
    }
    return new_word;
}


string* generate_subkeys(string key)
{
    string kbits = HexToBin(key);

    static string subkey[11];//in bits

    subkey[0] = kbits;

    string word[44];//in bits

    for (int w = 0; w <= 3; w++)// for first 4 words = the original key
    {
        word[w] = kbits.substr(w * 32, 32);// divide key for 4 words each word has 4 characters
    }

    for (int roundnum = 1; roundnum <= 10; roundnum++)
    {
        word[roundnum * 4] = xor_(word[4 * (roundnum - 1)], g_function(word[(4 * roundnum) - 1], roundnum - 1));
        subkey[roundnum] = word[roundnum * 4];
        for (int j = 1; j <= 3; j++)
        {
            word[(roundnum * 4) + j] = xor_(word[(4 * roundnum) + j - 1], word[4 * (roundnum - 1) + j]);
            subkey[roundnum] += word[(roundnum * 4) + j];
        }

    }
    return subkey;//in binary
}





string AESencryption(string txt, string key)
{
    string* ptrKeys;
    ptrKeys = generate_subkeys(key);

   // txt = ASCIIToBinary(txt);
    txt = xor_(txt, ptrKeys[0]);

    string sub_string[16];
    int col[16];
    int row[16];
    for (int round = 1; round <= 10; round++)
    {
        for (int i = 0; i < 16; i++)
        {
            sub_string[i] = txt.substr(i * 8, 8);

            row[i] = BinaryToDecimal(sub_string[i].substr(0, 4));
            col[i] = BinaryToDecimal(sub_string[i].substr(4, 4));
        }
        string B_tump[16];//store binary
        for (int i = 0; i < 16; i++)
        {
            B_tump[i] = HexToBin(SBox[row[i]][col[i]]);

        }

        string ShiftRow[16];
        int j = 0;

        for (int i = 0; i < 16; i++)
        {
            ShiftRow[i] = B_tump[j];
            j = j + 5;
            if (j > 15)
                j = j % 16;

        }

        string txt2d[4][4];
        int num = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                txt2d[j][i] = ShiftRow[num];

                num++;
            }
        }


        string tump, tump1, tt = "";
        string tumpmix[4];
        string txtmix[4][4];
        int Mix[4][4] = { {2, 3, 1, 1 }, { 1, 2, 3, 1 },{ 1, 1, 2, 3}, {3, 1, 1, 2 } };
        if (round != 10)
        {
            for (int k = 0; k < 4; k++)
            {
                for (int z = 0; z < 4; z++)
                {
                    for (int y = 0; y < 4; y++)
                    {

                        if (Mix[k][y] == 2)
                        {
                            tumpmix[y] = txt2d[y][z] + "0";
                            while (true)
                            {
                                tumpmix[y] = xor_(tumpmix[y], "100011011");

                                if (tumpmix[y][0] == '0')
                                {
                                    tumpmix[y] = tumpmix[y].substr(1, 8);
                                    break;
                                }
                            }
                        }
                        else if (Mix[k][y] == 3)
                        {
                            tumpmix[y] = txt2d[y][z] + "0";
                            while (true)
                            {
                                tumpmix[y] = xor_(tumpmix[y], "100011011");

                                if (tumpmix[y][0] == '0')
                                {
                                    tumpmix[y] = tumpmix[y].substr(1, 8);
                                    break;
                                }
                            }
                            tumpmix[y] = xor_(tumpmix[y], txt2d[y][z]);
                        }
                        else if (Mix[k][y] == 1)
                        {
                            tumpmix[y] = txt2d[y][z];
                        }
                    }

                    tump = xor_(tumpmix[0], tumpmix[1]);

                    tump = xor_(tump, tumpmix[2]);

                    tump = xor_(tump, tumpmix[3]);

                    txtmix[k][z] = tump;
                }
            }
            for (int i = 0; i < 4; i++)
            {
                for (int k = 0; k < 4; k++)
                {
                    tt += txtmix[k][i];
                }
            }
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                for (int k = 0; k < 4; k++)
                {
                    tt += txt2d[k][i];
                }
            }
        }

        txt = xor_(tt, ptrKeys[round]);

    }
    return txt;//in binary
}

string AESdecryption(string txt, string key)
{

    //txt = ASCIIToBinary(txt);
    //txt = HexToBin(txt);

    string* ptrKeys;
    ptrKeys = generate_subkeys(key);
    string sub_string[16];
    int col[16];
    int row[16];
    string txtmix[4][4];
    string txtmix2[4][4];
    string mat[16], ShiftRow[16], txt2d[4][4];
    string InverseMixColumn[4][4] = { "0E", "0B", "0D","09", "09","0E", "0B", "0D","0D","09","0E", "0B","0B", "0D","09","0E" };
    int counter = 0;
    int tumpp;

    for (int round = 10; round > 0; round--)
    {
        txt = xor_(txt, ptrKeys[round]);

        counter = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int o = 0; o < 4; o++)
            {
                txtmix[o][i] = txt.substr((o * 8) + (i * 32), 8);
                mat[counter] = txtmix[o][i];
                counter++;
            }

        }
        counter = 0;
        string shf[3];
        string tump;
        string tumpmix[4];
        if (round < 10)
        {
            for (int k = 0; k < 4; k++)
            {
                for (int z = 0; z < 4; z++)
                {
                    for (int y = 0; y < 4; y++)
                    {
                        if (InverseMixColumn[k][y] == "0E")
                        {
                            shf[0] = "00" + txtmix[y][z] + "0";
                            shf[1] = "0" + txtmix[y][z] + "00";
                            shf[2] = txtmix[y][z] + "000";
                            tump = xor_(shf[0], shf[1]);
                            tumpmix[y] = xor_(tump, shf[2]);

                            while (BinaryToDecimal(tumpmix[y].substr(0, 3)) > 0)
                            {
                                if (tumpmix[y][0] == '1')
                                {
                                    tumpmix[y] = xor_("10001101100", tumpmix[y]);
                                }
                                else if (tumpmix[y][1] == '1')
                                {
                                    tumpmix[y] = xor_("01000110110", tumpmix[y]);
                                }
                                else if (tumpmix[y][2] == '1')
                                {
                                    tumpmix[y] = xor_("00100011011", tumpmix[y]);
                                }
                            }
                            tumpmix[y] = tumpmix[y].substr(3, 8);

                        }
                        if (InverseMixColumn[k][y] == "0B")
                        {

                            shf[0] = "000" + txtmix[y][z];

                            shf[1] = "00" + txtmix[y][z] + "0";

                            shf[2] = txtmix[y][z] + "000";

                            tump = xor_(shf[0], shf[1]);

                            tumpmix[y] = xor_(tump, shf[2]);


                            while (BinaryToDecimal(tumpmix[y].substr(0, 3)) > 0)
                            {
                                if (tumpmix[y][0] == '1')
                                {
                                    tumpmix[y] = xor_("10001101100", tumpmix[y]);
                                }
                                else if (tumpmix[y][1] == '1')
                                {
                                    tumpmix[y] = xor_("01000110110", tumpmix[y]);
                                }
                                else if (tumpmix[y][2] == '1')
                                {
                                    tumpmix[y] = xor_("00100011011", tumpmix[y]);
                                }
                            }
                            tumpmix[y] = tumpmix[y].substr(3, 8);


                        }
                        if (InverseMixColumn[k][y] == "0D")
                        {

                            shf[0] = "000" + txtmix[y][z];

                            shf[1] = "0" + txtmix[y][z] + "00";

                            shf[2] = txtmix[y][z] + "000";

                            tump = xor_(shf[0], shf[1]);

                            tumpmix[y] = xor_(tump, shf[2]);


                            while (BinaryToDecimal(tumpmix[y].substr(0, 3)) > 0)
                            {
                                if (tumpmix[y][0] == '1')
                                {
                                    tumpmix[y] = xor_("10001101100", tumpmix[y]);
                                }
                                else if (tumpmix[y][1] == '1')
                                {
                                    tumpmix[y] = xor_("01000110110", tumpmix[y]);
                                }
                                else if (tumpmix[y][2] == '1')
                                {
                                    tumpmix[y] = xor_("00100011011", tumpmix[y]);
                                }
                            }
                            tumpmix[y] = tumpmix[y].substr(3, 8);

                        }
                        if (InverseMixColumn[k][y] == "09")
                        {
                            shf[0] = "000" + txtmix[y][z];

                            shf[1] = txtmix[y][z] + "000";

                            tumpmix[y] = xor_(shf[1], shf[0]);

                            while (BinaryToDecimal(tumpmix[y].substr(0, 3)) > 0)
                            {
                                if (tumpmix[y][0] == '1')
                                {
                                    tumpmix[y] = xor_("10001101100", tumpmix[y]);
                                }
                                else if (tumpmix[y][1] == '1')
                                {
                                    tumpmix[y] = xor_("01000110110", tumpmix[y]);
                                }
                                else if (tumpmix[y][2] == '1')
                                {
                                    tumpmix[y] = xor_("00100011011", tumpmix[y]);
                                }
                            }
                            tumpmix[y] = tumpmix[y].substr(3, 8);
                        }
                    }

                    tump = xor_(tumpmix[0], tumpmix[1]);

                    tump = xor_(tump, tumpmix[2]);

                    tump = xor_(tump, tumpmix[3]);

                    txtmix2[k][z] = tump;
                }
            }
            counter = 0;
            for (int i = 0; i < 4; i++)
                for (int l = 0; l < 4; l++)
                {
                    mat[counter] = txtmix2[l][i];
                    counter++;
                }
        }

        int j = 0;
        for (int i = 0; i < 16; i++)
        {
            ShiftRow[i] = mat[j];
            j += 13;
            if (j > 15)
            {
                j = j % 16;
            }

        }
        txt = "";

        for (int i = 0; i < 16; i++)
            txt += ShiftRow[i];

        for (int i = 0; i < 16; i++)
        {
            sub_string[i] = txt.substr(i * 8, 8);

            row[i] = BinaryToDecimal(sub_string[i].substr(0, 4));
            col[i] = BinaryToDecimal(sub_string[i].substr(4, 4));
        }
        string B_tump[16];
        txt = "";
        for (int i = 0; i < 16; i++)
        {
            B_tump[i] = HexToBin(ISBox[row[i]][col[i]]);
            txt += B_tump[i];
        }
    }

    return xor_(txt, ptrKeys[0]);//in bits
}

string handle_block(string message) {
    string new_message = "";
    string message_bit = ASCIIToBinary(message);
    int j = 0;
    if (message_bit.length() % 128 == 0)
    {
        new_message = message_bit;
    }
    else if (message_bit.length() > 128)
    {
        if (message_bit.length() % 128 != 0)
        {
            for (int i = 0; i < (128 - message_bit.length() % 128); i++)
            {
                new_message += "0";
                j = new_message.length();
            }
            new_message = new_message + message_bit;
        }

    }
    else if (message_bit.length() < 128)
    {
        for (int i = 0; i < (128 - message_bit.length()); i++)
        {
            new_message += "0";
            j = new_message.length();
        }
        new_message = new_message + message_bit;
    }
    num_of_zeros = j;
    return new_message;
}

int main()
{

    string message, key;
    cout << "Enter Your Message: ";
    cin >> message;
    cout << "\nEnter Your Key: ";
    cin >> key;

    // key length 128bit or 32 hexa or 16 characters
    while (key.length() != 16)
    {
        cout << "Error the key length is invalid!! (the key must be 16 characters)" << endl;
        cout << "Enter the Key: ";
        cin >> key;
    }
 key = ASCIIToBinary(key);
    key = BinToHex(key);
    message = handle_block(message);

    int size = message.length() / 128;

    string* block = new string[size];

    string cipher = "";
    string plaintxt = "";

    for (int i = 0; i < size; i++)
    {
        block[i] = message.substr(i * 128, 128);

        cipher += AESencryption((block[i]), key);
    }

    for (int i = 0; i < size; i++)
    {
        plaintxt += AESdecryption(cipher.substr(i * 128, 128), key);
    }

    cout << "\nCipher Text (in Hexa): \t" << BinToHex(cipher) << endl;
    cout << "\nCipher Text (in ASCI): \t" << BinaryToASCII(cipher) << endl;

    plaintxt = plaintxt.substr(num_of_zeros, plaintxt.length() - num_of_zeros + 1);
    plaintxt = BinaryToASCII(plaintxt);
    cout << "\nPlain Text is : " << plaintxt << endl;

}
