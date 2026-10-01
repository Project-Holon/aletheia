/*
 * function: func_021DF2E0
 * address: 0x021DF2E0
 * packet: pkt_ov137_021DF2E0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E1830 0x021E1830 thumb ov137
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0x60]; u16 angles[5]; } Obj;
extern int func_021E1830(void *, int, int);
extern int func_021DCBC4(void *, int, void *, int);
int func_021DF2E0(Obj *obj)
{
    u8 *p = (u8 *)obj;
    struct { u16 angle, mask, entries[6]; } buf;
    int i;
    u8 *q;
    buf.angle = *(int *)(p + 0x58) / 4096;
    *(int *)(p + 0x1c) = 0;
    for (i = 0; i < *(int *)(p + 0x30); i++) {
        q = p + 0x2e0 + i * 180;
        {
        int angle;
        angle = obj->angles[i];
        buf.entries[*(int *)(q + 16)] = angle;
        if (func_021E1830(p, angle << 12, *(int *)(p + 0x30)) == 1)
            *(int *)(p + 0x1c) |= 1 << *(int *)(q + 12);
        }
    }
    buf.mask = *(int *)(p + 0x1c);
    if (func_021DCBC4(*(void **)(p + 0xdc), 10252, &buf, 16) == 1) *(int *)p = 35;
    return 0;
}
