int rand_w(unsigned int in) {
    size_t y = 1;
    size_t a = 4 * in;
    int out = 0;
    x = log2(a) + 1;
    while (y != a) {
        y = y * 3 + 1;
        y = y % (1 << x);
        out++;
    }
    return out;
}
