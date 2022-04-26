#include <iostream>
#include <vector>

using byte = unsigned char;



template<typename T>
std::string base64Encode(T& msg){
    std::string encoded_string = "";
    std::string lookup_string = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    encoded_string.reserve( (msg.size() / 3 + (msg.size() % 3 > 0) ) * 4 );

    int j = 0;
    int temp = 0;
    for(int i = 0; i < msg.size()/3; ++i){
        temp |= msg[j++] << 16;
        temp |= msg[j++] << 8;
        temp |= msg[j++];

        for(int i = 18, mask = (0xfc << 16); i >=0; i -= 6, mask >>= 6){
            encoded_string += lookup_string[ (temp & mask) >> i ];
        }

        temp = 0;
    }

    if(msg.size() % 3 == 1){
        std::cout << "need 2 paddings\n";
        temp = msg.back() << 16;
        encoded_string += lookup_string[ (temp & 0x00fc0000) >> 18];
        encoded_string += lookup_string[ (temp & 0x0003f000) >> 12];
        encoded_string += "==";
    }else if(msg.size() % 3 == 2){
        std::cout << "need 1 padding\n";
        temp |= *(msg.end()-2) << 16;
        temp |= *(msg.end()-1) << 8;
        encoded_string += lookup_string[ (temp & 0x00fc0000) >> 18 ];
        encoded_string += lookup_string[ (temp & 0x0003f000) >> 12 ];
        encoded_string += lookup_string[ (temp & 0x00000fc0) >> 6];
        encoded_string += "=";
    }
    return encoded_string;
}

std::vector<byte> base64Decode(const std::string& encoded_msg_){

    if(encoded_msg_.size() % 4){
        throw std::runtime_error("Invalid base64 encoding");
    }

    int padding = 0;
    if(encoded_msg_[encoded_msg_.size() - 1] == '=') ++padding;
    if(encoded_msg_[encoded_msg_.size() - 2] == '=') ++padding;

    std::vector<byte> decoded_msg(encoded_msg_.size() * 3 / 4 - padding, 0);
    int j = 0;

    for(int i = 0; i < encoded_msg_.size(); i += 4){
        size_t tmp = 0;
        std::string sub = encoded_msg_.substr(i, 4);

        for(auto c: sub){
            tmp <<= 6;
            if(c >= 0x41 && c <= 0x5a){
                tmp |= (c - 0x41);
            }else if(c >= 0x61 && c <= 0x7a){
                tmp |= (c - 0x47);
            }else if(c >= 0x30 && c <= 0x39){
                tmp |= (c + 0x04);
            }else if(c == 0x2b){
                tmp |= 0x3e;
            }else if(c == 0x2f){
                tmp |= 0x3f;
            }else if(c != '='){
                throw std::runtime_error("Invalid character in message");
            }
        }

        int length = (i == encoded_msg_.size() - 4) ? padding : 0;
        for(int t = 3; t > length; --t){
            decoded_msg[j++] = ( tmp >> (8*(t-1)) ) & 0x000000ff;
        }
    }

    return decoded_msg;
}