/*
 * function: func_021F1268
 * address:  0x021F1268
 * packet:   pkt_ov032_021F1268
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1268 0x021F1268 thumb
 *   func_021659F0 0x021659F0 thumb ov010
 *   func_021F0F44 0x021F0F44 thumb
 *   func_021F1080 0x021F1080 thumb
 */

typedef unsigned char u8;

extern int func_021659F0(u8 *q, int delta);
extern char *func_021F0F44(char *this, u8 id);
extern void func_021F1080(char *this, char *e, int i, int j);

void func_021F1268(char *this)
{
    int i;
    char *e;

    for (i = 0; i < *(u8 *)(this + 0x7d); i++) {
        e = func_021F0F44(this, func_021659F0(*(u8 **)(this + 0x3c), *(u8 *)(this + 0x7c) + i));
        if (*(int *)(e + 0x30) == 0 || *(int *)(e + 0x2c) != 0)
            func_021F1080(this, e, 0, 0);
    }
}
