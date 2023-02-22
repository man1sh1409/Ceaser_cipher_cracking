#include<bits/stdc++.h>
using namespace std;
string alpa="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char freq_table[]={'e','t','a','o','i','n','s','h',
                    'r','d','l','c','m','w','f','g',
                    'y','p','b','v','k','j','x','q'
};

string uppercase(string &msg){
    string ms="";
    for(int i=0;i<msg.length();i++){
        if(msg[i]==' ')ms+=" ";
        else{
            if(msg[i]>='a' and msg[i]<='z')
            ms+=char(msg[i]-32);
            else
            return msg;
        }
    }
    return ms;
}



string encrpt(string msg,int key){
    string enc;
    msg=uppercase(msg);
    cout<<"original messaage is :"<<msg<<endl;
    int len=msg.size();
    for(int i=0;i<len;i++){
        if(msg[i]==' ')
            enc+=" ";
        else{
            int shift=(alpa.find(msg[i])+key)%26;
            enc+=alpa[shift];
        }
    }
    return enc;
}



string decrpt(string enc,int key){
    string dec;
    //enc=uppercase(enc);
    int len=enc.size();
    for(int i=0;i<len;i++){
        if(enc[i]==' ')
            dec+=" ";
        else{
            int shift=alpa.find(enc[i])-key;
            
            if(shift<0)shift+=26;
            dec+=alpa[shift];
        }
    }
    return dec;
}


void decode_brutForce(string &ctext){
    int len=ctext.size();
    for(int key=1;key<26;key++){
        string msg="";
        for(int i=0;i<len;i++){
            if(ctext[i]==' ')
            msg+=" ";
            else{
                int shift=alpa.find(ctext[i])-key;
                
                if(shift<0)shift+=26;
                msg+=alpa[shift];
            }
        }
        cout<<"message with shift key "<<key<<": "<<msg<<endl;
    }
}

bool custom(pair<int,char>&a,pair<int,char>&b){
    return a.first>b.first;
}


vector<int> decode_freqAnalysis(string &ctxt){
    unordered_map<char,int>freq;
    for(char i:ctxt){
        freq[i]++;
    }
    vector<pair<int,char>>v;
    for(auto i:freq){
        v.push_back({i.second,i.first});
    }
    // sort using maximum frequency 
    sort(v.begin(),v.end(),custom);
    
    vector<int>possible_key_length;
    int j=0;
    for(auto i:v){
        int key=i.second-'E';
        possible_key_length.push_back(key);
    }

    return possible_key_length;
}

int main(){
    string msg;
    //e.g msg= hii my name is manish kumar i am final year student of mnit jaipur
    cout<<"Enter message to encrpyt\n";
    getline(cin,msg);
    int key;
    cout<<"enter key shift length \n";
    cin>>key;
    string cipher_text=encrpt(msg,key);
    cout<<"encrypted message is : "<<cipher_text<<endl;
    string dec=decrpt(cipher_text,key);
    cout<<"decrypted message is : "<<dec<<endl;
    cout<<endl;
    cout<<"********************************************************************"<<endl;
    

    //use  switch case to for better user experince
    // here are the two method for cracking ceaser cipher
    //1.decode_brutForce();  T.C=0(25*len(cipher_text))
    //2.decode_freqAnalysis(); T.C=0(len(cipher_text))


     decode_brutForce(cipher_text);
    // vector<int>shiftKey=decode_freqAnalysis(cipher_text);
    
    // for(int i:shiftKey){
    //     string dec=decrpt(cipher_text,i);
    //     cout<<dec<<endl;
    // }
    
    return 0;
}