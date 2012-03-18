namespace IO {
   #define MAXBUFF (1<<18)
    char buffer[MAXBUFF], *p = buffer+MAXBUFF;

    inline char read_char() {
        if( p == buffer+MAXBUFF ) {
            fread( buffer, 1, MAXBUFF, stdin );
            p = buffer;
        }
        return *p++;
    }

    inline int read_signed_int() {
        char c;
        while( !isdigit(c = read_char()) and c != '-' );
        int sign = 1;
        if (c == '-') sign = -1, c = read_char();
        int ret = c-'0';
        while( isdigit(c = read_char()) ) ret = ret * 10 + c-'0';
        return ret * sign;
    }

    inline int read_unsigned_int() {
        char c;
        while( !isdigit(c = read_char()) );
        int ret = c-'0';
        while( isdigit(c = read_char()) ) ret = ret * 10 + c-'0';
        return ret;
    }
}
