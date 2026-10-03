/*
 * function: func_021BAF70
 * address: 0x021BAF70
 * packet: pkt_ov217_021BAF70
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   func_021BC600 0x021BC600 thumb ov217
 *   func_021BC608 0x021BC608 thumb ov217
 *   func_021BC6D0 0x021BC6D0 thumb ov217
 *   func_021BBAD0 0x021BBAD0 thumb ov217
 *   func_021BB934 0x021BB934 thumb ov217
 *   func_021BB91C 0x021BB91C thumb ov217
 *   func_021BB910 0x021BB910 thumb ov217
 *   func_021BC5FC 0x021BC5FC thumb ov217
 *   func_021BBDAC 0x021BBDAC thumb ov217
 *   func_021BBD40 0x021BBD40 thumb ov217
 *   func_021BC6DC 0x021BC6DC thumb ov217
 *   func_021BC580 0x021BC580 thumb ov217
 *   func_021BC6EC 0x021BC6EC thumb ov217
 *   func_021BC6F4 0x021BC6F4 thumb ov217
 *   func_021BBAA4 0x021BBAA4 thumb ov217
 *   func_021BC06C 0x021BC06C thumb ov217
 *   func_021C09B8 0x021C09B8 thumb ov217
 *   func_021BC428 0x021BC428 thumb ov217
 *   func_021BC0E8 0x021BC0E8 thumb ov217
 *   func_0203630C 0x0203630C arm
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_02035BA4 0x02035BA4 arm
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_0203630C(void);
extern u32 func_020362DC(void);
extern int func_02035C08(void *p);
extern int func_02035BA4(void *p);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern void func_020061E4(u32 a);
extern void *func_021C09B8(void *p);
extern void func_021BC600(void *p);
extern void func_021BC608(void *p);
extern u32 func_021BC6D0(void *p);
extern int func_021BC6DC(void *p);
extern void func_021BBAD0(void *p);
extern void func_021BB934(void *p, int v);
extern void func_021BB91C(void *p);
extern void func_021BB910(void *p, int v);
extern u32 func_021BC5FC(void *p);
extern void func_021BBDAC(void *p);
extern void func_021BBD40(void *p, int v);
extern void func_021BC580(char *p, int i);
extern void func_021BC6EC(void *p, u8 v);
extern int func_021BC6F4(void *p, u8 v);
extern void func_021BBAA4(void *p, u8 v);
extern int func_021BC06C(char *p);
extern int func_021BC428(void *p);
extern void func_021BC0E8(void *p);

void func_021BAF70(char *p)
{
    u32 trg = func_0203630C();
    u32 keys = func_020362DC();
    int sel = func_02035C08(p + 0x64);
    int flag;
    u32 a;
    u32 b;
    flag = func_02035C08(func_021C09B8(*(void **)p));
    func_02035CB8(&a, &b);
    if (trg & 0xc0) {
        func_021BC600(p);
    } else {
        func_021BC608(p);
    }
    if (func_021BC6D0(p) != 0 || flag == 0) {
        func_020061E4(0x551);
        func_021BBAD0(p);
        func_021BB934(p, 1);
        func_021BB91C(p);
        func_021BB910(p, 6);
        return;
    }
    if ((keys & 0x40) || ((trg & 0x40) && *(u8 *)(p + 0x32) != 0 && func_021BC5FC(p) > 10)) {
        func_021BBDAC(p);
        func_021BBD40(p, -1);
        func_021BB91C(p);
        func_021BB910(p, 3);
        func_021BB910(p, 2);
        return;
    }
    if ((keys & 0x80) || ((trg & 0x80) && *(u8 *)(p + 0x32) < func_021BC6DC(p) - 1 && func_021BC5FC(p) > 10)) {
        func_021BBDAC(p);
        func_021BBD40(p, 1);
        func_021BB91C(p);
        func_021BB910(p, 3);
        func_021BB910(p, 2);
        return;
    }
    if (keys & 1) {
        func_021BC580(p, 2);
        func_021BC6EC(p, *(u8 *)(p + 0x32));
        func_020061E4(0x54c);
        func_021BB910(p, 9);
        func_021BB91C(p);
        return;
    }
    if (sel >= 0 && sel <= 9) {
        if (b >= 0x18 && b <= 0xa8 && func_021BC6F4(p, (u8)sel) == 1) {
            func_021BBAA4(p, (u8)sel);
            func_021BC6EC(p, *(u8 *)(p + 0x32));
            func_021BC580(p, 2);
            func_020061E4(0x54c);
            func_021BC06C(p);
            func_021BB91C(p);
            func_021BB910(p, 7);
        }
        return;
    }
    if (keys & 2) {
        func_020061E4(0x551);
        func_021BBAD0(p);
        func_021BB934(p, 0);
        func_021BB91C(p);
        func_021BB910(p, 6);
        return;
    }
    if (func_02035BA4(p + 0x90) == 0 || func_02035C08(p + 0x90) == 0) {
        if (func_021BC428(p) == 1) {
            func_021BBDAC(p);
            func_021BC0E8(p);
            func_021BB91C(p);
            func_021BB910(p, 4);
            func_021BB910(p, 1);
        }
    }
}
