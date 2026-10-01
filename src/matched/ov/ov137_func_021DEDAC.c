/*
 * function: func_021DEDAC
 * address: 0x021DEDAC
 * packet: pkt_ov137_021DEDAC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E1FA0 0x021E1FA0 data a2
 *   func_021E16AC 0x021E16AC thumb ov137
 *   func_021E1768 0x021E1768 thumb ov137
 *   func_021DEB10 0x021DEB10 thumb ov137
 *   func_02184180 0x02184180 thumb ov022
 *   func_021DEF6C 0x021DEF6C thumb ov137
 *   func_021E0304 0x021E0304 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0x90]; void *slots[5]; void *other[5]; } Obj;
extern const u16 d_021E1FA0[][5];
extern u8 *func_021E16AC(void *, int);
extern int func_021E1768(char *, int);
extern void *func_021DEB10(void *);
extern void *func_02184180(void *, u8);
extern void func_02008500(void *, void *);
extern void func_021DEF6C(void *);
extern void func_02005D90(int, int);
extern void func_021E0304(void *);
int func_021DEDAC(Obj *obj)
{
    u8 *p = (u8 *)obj;
    u8 *q;
    int i, count;
    q = func_021E16AC(p, 24);
    *(int *)(q + 16) = *(int *)(p + 0x2c);
    count = *(int *)(p + 0x30);
    *(int *)(q + 20) = count;
    *(int *)(q + 4) = d_021E1FA0[count][*(int *)(p + 0x2c)];
    for (i = 0; i < 5; i++) {
        if (func_021E1768((char *)p, i)) {
            obj->slots[i] = func_02184180(func_021DEB10(p), i);
            func_02008500(obj->slots[i], obj->other[i]);
        }
    }
    func_021DEF6C(p);
    *(int *)(p + 0x120) = *(int *)(q + 4) << 12;
    *(int *)p = 17;
    func_02005D90(1157, 65535);
    *(int *)(*(u8 **)(*(u8 **)(p + 0xd8) + 0x14) + 0x14) = 1;
    func_021E0304(p);
    return 1;
}
