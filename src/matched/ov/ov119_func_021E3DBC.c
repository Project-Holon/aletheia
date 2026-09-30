/*
 * function: func_021E3DBC
 * address: 0x021E3DBC
 * packet: pkt_ov119_021E3DBC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E3D04 0x021E3D04 thumb ov119
 */
extern int func_0201AA18(void *);
extern void *func_0201AB28(void *, int);
extern void *func_020185F0(void *);
extern unsigned char func_021E3D04(void *, unsigned int);
void func_021E3DBC(char *p, void *party, unsigned char *out)
{
    int count;
    unsigned char i;
    count = func_0201AA18(party);
    for (i = 0; i < 6; i++) {
        if (count > i)
            out[i] = func_021E3D04(func_020185F0(func_0201AB28(party, i)), *(unsigned short *)(p + 0x5F4));
        else
            out[i] = 0;
    }
}
