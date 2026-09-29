/*
 * function: func_021F13A0
 * address:  0x021F13A0
 * packet:   pkt_ov032_021F13A0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F13A0 0x021F13A0 thumb
 *   func_021F0F44 0x021F0F44 thumb
 *   func_021F0F30 0x021F0F30 thumb
 *   func_021F1144 0x021F1144 thumb
 *   func_021F1418 0x021F1418 thumb
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern char *func_021F0F44(char *this, u8 id);
extern void func_021F0F30(char *e, int a, int b);
extern void func_021F1144(char *this, char *e, int a, int b, int c, void *d);
extern void func_021F1418(void);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern u8 *func_02031290(void);
extern void func_02082BCC(void *p, int v, int n);

void func_021F13A0(char *this, int a, int b, u8 c, int s)
{
    char *e;
    u8 *r;

    e = func_021F0F44(this, 0xff);
    if (e != 0) {
        func_020311B8(*(u32 *)(this + 0xa0), (void *)func_021F1418, 0x18, 0);
        r = func_02031290();
        func_02082BCC(r, 0, 0x18);
        *(char **)(r + 0xc) = this;
        r[1] = c;
        *(char **)(r + 8) = e;
        *(int *)(r + 4) = s;
        *(int **)(r + 0x14) = (int *)(this + 0xa8);
        *(int *)(this + 0xa8) = *(int *)(this + 0xa8) + 1;
        func_021F0F30(e, b, 0);
        func_021F1144(this, e, a, s, 0, r + 0x10);
    }
}
