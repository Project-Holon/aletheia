/*
 * function: func_021E024C
 * address: 0x021E024C
 * packet: pkt_ov183_021E024C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021E02F6
 * symbols:
 *   func_021FCD0C 0x021FCD0C thumb ov186
 *   func_021FCDA8 0x021FCDA8 thumb ov186
 *   func_02035D20 0x02035D20 arm
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021E03B0 0x021E03B0 thumb ov183
 *   func_02012944 0x02012944 thumb
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 */
typedef unsigned char u8;
extern void func_021FCD0C(void *);
extern int func_021FCDA8(void *);
extern int func_02035D20(unsigned int *, unsigned int *);
extern int func_021FB4B4(int, unsigned int, unsigned int);
extern void func_021FD860(int, int, int *);
extern void func_021E03B0(char *, char *, int);
extern void *func_02012944(void *);
extern int func_0200856C(void *);
extern int func_02008570(void *);
int func_021E024C(char *p, char *q)
{
    int selected, pressed;
    unsigned int x, y;
    func_021FCD0C(*(void **)(p + 0x18));
    selected = func_021FCDA8(*(void **)(p + 0x18));
    pressed = func_02035D20(&x, &y);
    pressed &= func_021FB4B4(*(int *)(p + 0xC), x, y);
    if (selected != -1) {
        unsigned int x1, y1;
        int args[2];
        void *v;
        int a;
        func_02035D20(&x1, &y1);
        args[0] = x1;
        args[1] = y1;
        func_021FD860(*(int *)(p + 0x40), 1, args);
        v = func_02012944(*(void **)(q + 0x10));
        a = func_0200856C(v);
        *(u8 *)(q + 0x17) = func_02008570(v);
        *(u8 *)(q + 0x16) = a;
        func_021E03B0(p, q, 2);
        *(int *)(p + 0x50) = 0;
        return 1;
    } else if (pressed != 0) {
        unsigned int x2, y2;
        int args[2];
        func_02035D20(&x2, &y2);
        args[0] = x2;
        args[1] = y2;
        func_021FD860(*(int *)(p + 0x40), 1, args);
        *(int *)(p + 0x50) = 0;
        return 1;
    }
    return 0;
}
