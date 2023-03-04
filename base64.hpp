void base64_encode(int len, char* in, char* out) {
    char base64_char[66] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=" };
    int ix = 0;
    int ix_2 = 0;
    char *out_ = new char[len*2];
    for (int i = 0; i < len * 8; i++) {
        out_[ix_2] = (out_[ix_2] << 1) + ((in[ix] >> (7 - i % 8)) % 2);
        if (i % 6 == 5) { ix_2++; }
        if (i % 8 == 7) { ix++; }
    }
    out_[ix_2] = out_[ix_2] << (5 - ((len * 8 - 1) % 6));
    for (int i = 1; (((i - 1) * 6 + (5 - (len * 8 - 1) % 6)) % 8) != 0; i++) {
        out_[ix_2 + i] = 64;
    }
    for (int i = 0; i < strlen(out_); i++) {
        out[i] = base64_char[out_[i]];
    }
    delete[] out_;
}
void base64_dencode(int len, char* in, char* out_) {
    int base64_char[128] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,62,0,0,0,63,52,53,54,55,56,57,58,59,60,61,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,0,0,0,0,0,0,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,0,0,0,0,0};
    int ix = 0;
    int ix_2 = 0;
    for (int i = 0; i < len * 6; i++) {
        if(in[ix] == '='){break;}
        out_[ix_2] = (out_[ix_2] << 1) + ((base64_char[in[ix]] >> (5 - i % 6)) % 2);
        if (i % 8 == 7) { ix_2++; }
        if (i % 6 == 5) { ix++; }
    }
    out_[ix_2] = out_[ix_2] << ((8-(ix*6)%8)%8);
}
