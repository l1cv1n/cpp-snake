union Color
{
    unsigned int hex;

#if IS_BIG_ENDIAN
    struct { unsigned char a, r, g, b; };
#else
    struct { unsigned char b, g, r, a; };
#endif
};
