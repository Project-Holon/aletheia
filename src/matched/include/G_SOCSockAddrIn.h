#ifndef ALETHEIA_G_SOCSOCKADDRIN_H
#define ALETHEIA_G_SOCSOCKADDRIN_H
/* g_021ACF80 (arm9) */
struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned long addr;
};
#endif
