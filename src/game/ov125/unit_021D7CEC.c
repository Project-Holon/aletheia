/*
 * file:     unit_021D7CEC.c
 * unit:     yes
 * function: func_021D7CEC, func_021D7CF4, func_021D7D20, func_021D7D24, func_021D7D30, func_021D7D88, func_021D7E20, func_021D7E80, func_021D7F60, func_021D7FA0, func_021D80E0, func_021D824C, func_021D8438, func_021D8444, func_021D8588, func_021D858C, func_021D8598, func_021D85B4, func_021D85C0, func_021D85DC, func_021D85E8, func_021D85F4, func_021D8600, func_021D860C, func_021D8654, func_021D8694, func_021D8754, func_021D879C, func_021D87FC, func_021D885C, func_021D88BC, func_021D88F0, func_021D891C, func_021D89EC, func_021D8B3C, func_021D8B44, func_021D8BC0, func_021D8BE4, func_021D8BF8, func_021D8C14
 * address:  0x021D7CEC
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02087058 0x02087058 arm
 *   func_02086FE8 0x02086FE8 arm
 *   d_021D9E40 0x021D9E40 data a4
 *   func_021D7874  0x021D7874  arm  ov125
 *   d_021DA0B4 0x021DA0B4 data a4
 *   d_021D9640 0x021D9640 data a4
 *   SOC_GetHostByName 0x0215F650 arm ov009
 *   func_0215FA9C 0x0215FA9C arm ov009
 *   d_021D9F80 0x021D9F80 data a4
 *   d_021DA258 0x021DA258 data a4
 *   func_0215F428 0x0215F428 arm ov009
 *   func_0215C910 0x0215C910 arm ov009
 *   func_0215FC80 0x0215FC80 arm ov009
 *   func_021D8C5C 0x021D8C5C arm ov125
 *   SOC_Shutdown 0x0215F638 arm ov009
 *   SOC_Close 0x0215F644 arm ov009
 *   d_021DA040 0x021DA040 data a4
 *   OS_GetTick 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 *   func_0215F480 0x0215F480 arm ov009
 *   func_021D7CAC 0x021D7CAC arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   func_0215F590 0x0215F590 arm ov009
 *   func_0215F4DC 0x0215F4DC arm ov009
 *   d_021D9E40b 0x021D9E40 data a4
 *   d_021DA18C 0x021DA18C data a4 ov125
 *   func_020853C0 0x020853C0 arm
 *   func_02085868 0x02085868 arm
 *   func_020855BC 0x020855BC arm
 *   func_02085A38  0x02085A38  arm
 *   func_02167FA8 0x02167FA8 arm ov009
 *   func_02168040 0x02168040 arm ov009
 *   func_02059E38 0x02059E38 arm
 *   d_021D8D30 0x021D8D30 data a4
 *   func_021D7770  0x021D7770  arm
 *   func_021D770C  0x021D770C  arm ov125
 *   func_021D7BCC 0x021D7BCC arm ov125
 *   func_021D7C48  0x021D7C48  arm  ov125
 *   func_021D7BDC  0x021D7BDC  arm ov125
 *   func_021D7C14  0x021D7C14  arm ov125
 *   func_021D7A10 0x021D7A10 arm ov125
 *   d_021D8CD0 0x021D8CD0 data a4
 *   func_02088168 0x02088168 arm
 *   func_02162248 0x02162248 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   d_021DAA8C 0x021DAA8C data a4
 *   d_021DAA88 0x021DAA88 data a4
 *   d_021DAAAC 0x021DAAAC data a4
 *   d_021D8D38 0x021D8D38 data a4
 *   func_02082D44 0x02082D44 arm
 *   func_0208CC78 0x0208CC78 arm
 *   func_021D7C7C 0x021D7C7C arm ov125
 *   func_0208CADC 0x0208CADC arm
 */
#include "../../matched/include/G_Clear.h"
#include "../../matched/include/Obj23010.h"
#include "../../matched/include/Obj14013.h"

#define D(o) (*(int *)(d_021D9E40 + (o)))
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long long u64;

typedef struct { u8 size, family; u16 port; u32 address; } Address;

typedef unsigned long u32_021D8438;

typedef unsigned int u32_021D8444;

typedef struct { u8 b[301]; } Sav;

typedef struct { int w[0x138 / 4]; } Blob;

typedef struct { unsigned words[0x230/4]; } Packet_021D860C;

typedef struct { unsigned short a,b; long long value; } Packet_021D8654;

typedef struct { unsigned words[0x18a4/4]; } Data_021D8694;

typedef struct { Data_021D8694 data; int length; char bytes[256]; } Packet_021D8694;

typedef struct { unsigned words[4]; } Data_021D8754;

typedef struct { unsigned short a,b; Data_021D8754 data; unsigned tail[2]; } Packet_021D8754;

typedef struct { unsigned short a,b; unsigned words[2]; int value; unsigned tail[3]; } Packet_021D879C;

typedef struct { unsigned short a,b; unsigned words[2]; int value; unsigned tail[3]; } Packet_021D87FC;

typedef struct { unsigned short a,b; unsigned words[2]; int value; unsigned tail[3]; } Packet_021D885C;

typedef signed short s16;

typedef struct {int a,b,c;} Triple;

typedef struct {int a,b;} Pair;

typedef struct { int words[8]; } Table;

extern int func_02087058(void);
extern void func_02086FE8(void);
extern void func_021D7874(void);
extern void func_020853C0(void *, void (*)(void *), int, void *, int, unsigned);
extern void func_02085868(void *);
extern void *SOC_GetHostByName(const char *);
extern char *func_0215FA9C(unsigned);
extern char *func_02094798(char *dst, const char *src);
extern int func_0215F428(int, int, int);
extern unsigned long func_0215C910(char *name);
extern int func_0215FC80(int s, void *con);
extern int SOC_Shutdown(int s, int how);
extern int SOC_Close(int s);
extern void func_021D8C5C(void *);
extern u64 OS_GetTick(void);
extern int func_0215F480(int, const Address *);
extern void func_021D7CAC(void);
extern void func_021D7CC0(void);
extern int func_0215F590(int, void *, int, int);
extern int func_0215F4DC(int, void *, int, int);
extern void func_020855BC(void *);
extern void func_02085A38(u32_021D8438 msec);
extern int func_02167FA8(char *svl, void *result);
extern int func_02168040(void);
extern int func_02059E38(int *, int *);
extern void func_021D7770(int, int, int);
extern void func_021D770C(void);
extern unsigned func_021D7BCC(void);
extern int func_021D7C48(void);
extern char *func_021D7BDC(void);
extern int func_021D7C14(void);
extern int func_021D7A10(int id, void *buf, int x, int sz);
extern void *func_02092344(void *dest, const void *src, unsigned int n);
extern void func_02088168(u32 *buffer);
extern void func_02162248(void *, u32);
extern void MI_CpuFill8(void *, u32, u32);
extern void func_02082D44(const void *, void *, u32);
extern u32 func_0208CC78(const char *);
extern char *func_021D7C7C(u32);
extern char *func_0208CADC(char *destp, const char *srcp);
int func_021D7CEC(void *p);
int func_021D7CF4(void);
void func_021D7D20(void);
void func_021D7D24(void *p);
int func_021D7D30(void);
int func_021D7D88(const char *s);
int func_021D7E20(const char *s, char *out);
int func_021D7E80(void);
void func_021D7F60(void);
int func_021D7FA0(void);
int func_021D80E0(void);
void func_021D81EC(void *a0);
int func_021D824C(void);
void func_021D8438(int msec);
int func_021D8444(void);
void func_021D8588(void);
void func_021D858C(void);
void func_021D8598(int a, int b, int c);
void func_021D85B4(void);
unsigned func_021D85C0(void);
int func_021D85DC(void);
char *func_021D85E8(void);
int func_021D85F4(void);
int func_021D8600(int n);
int func_021D860C(const Packet_021D860C *p, int n);
int func_021D8654(int value, int n);
int func_021D8694(const Data_021D8694 *data, const void *bytes, int length, int n);
int func_021D8754(Data_021D8754 *data, int n);
int func_021D879C(int value, int n);
int func_021D87FC(int value, int n);
int func_021D885C(int value, int n);
int func_021D88BC(u32 a, u32 b, u32 c, u32 n);
int func_021D88F0(u32 a, u32 b, u32 n);
int func_021D891C(int n);
int func_021D89EC(int n);
int func_021D8B3C(void);
void func_021D8B44(void);
void func_021D8BC0(u32 value);
void func_021D8BE4(int a);
void func_021D8BF8(int a, int b);
void func_021D8C14(const char *s, u8 *p);
extern char d_021D9E40[];
extern char d_021DA0B4[];
extern char d_021D9640[];
extern char d_021D9F80[];
extern u8 d_021DA258[];
extern u8 d_021DA040[];
extern struct Clear d_021D9E40b;
extern char d_021DA18C[];
extern const char d_021D8D30[];
extern const Table d_021D8CD0;
extern u8 d_021DAA8C[];
extern u8 d_021DAAAC[];
extern u8 *d_021DAA88;
extern const u32 d_021D8D38[];




int func_021D7CEC(void *p){return 1;}




int func_021D7CF4(void){if(!func_02087058())func_02086FE8();*(int*)(((char *)&d_021D9E40)+0x270)=16;return 1;}



void func_021D7D20(void){}



void func_021D7D24(void *p)
{
    func_021D7874();
}







int func_021D7D30(void) {
 func_020853C0(d_021DA0B4, func_021D7D24, 0, d_021D9640, 0x800, ((u32 *)d_021D9E40)[0x270/4]);
 func_02085868(d_021DA0B4);
 return 1;
}








int func_021D7D88(const char *s) {
 int digits=0, dots=0;
 while (*s) {
  if (*s >= '0' && *s <= '9') {
   if (++digits >= 4) return 0;
  } else if (*s == '.') {
   if (digits == 0) return 0;
   ++dots;
   digits=0;
   if(dots >= 4) return 0;
  } else return 0;
  ++s;
 }
 if(dots==3 && digits!=0) return 1;
 return 0;
}








int func_021D7E20(const char *s, char *out) {
 void *p;
 if (!func_021D7D88(s)) {
  p=SOC_GetHostByName(s);
  if (p) {
   func_02094798(out, func_0215FA9C(***(unsigned ** *)&((struct Obj23010 *)p)->fC));
  } else return 0;
 } else {
  func_02094798(out,s);
 }
 return 1;
}






/*
 * lever: final halfword swap ORs the right-shifted half before the left-shifted half; reversing them left two byte mismatches.
 */
int func_021D7E80(void)
{
    char out[16];
    u32 value;
    ((u32 *)d_021D9E40)[0x26c/4] = func_0215F428(2, 1, 0);
    if (((u32 *)d_021D9E40)[0x26c/4] == -1u) {
        ((u32 *)d_021D9E40)[0x250/4] = 3;
        return 0;
    }
    if (!func_021D7E20(d_021D9F80, out)) {
        ((u32 *)d_021D9E40)[0x250/4] = 5;
        return 0;
    }
    value = func_0215C910(out);
    value = ((value >> 8) & 0x00ff00ff) | ((value << 8) & 0xff00ff00);
    ((u32 *)d_021D9E40)[0x264/4] = (value >> 16) | (value << 16);
    func_021D8C14(d_021D9F80, d_021DA258);
    if (func_0215FC80(((u32 *)d_021D9E40)[0x26c/4], d_021DA258) < 0) {
        ((u32 *)d_021D9E40)[0x250/4] = 15;
        return 0;
    }
    return 1;
}





void func_021D7F60(void) {
 if (((u32 *)d_021D9E40)[0x26c/4] == -1u) return;
 SOC_Shutdown(((u32 *)d_021D9E40)[0x26c/4], 2);
 SOC_Close(((u32 *)d_021D9E40)[0x26c/4]);
 ((u32 *)d_021D9E40)[0x26c/4] = -1u;
 func_021D8C5C(d_021DA258);
}





/*
 * lever: port byte swap keeps both explicit masks; timeout casts after unsigned 64-bit subtraction, preserving the original subs before the signed comparison.
 */
int func_021D7FA0(void)
{
    Address address;
    int start, result;
    address.size = 8;
    address.family = 2;
    address.port = ((*(u16 *)(d_021DA040 + 0x40) >> 8) & 0xff) | ((*(u16 *)(d_021DA040 + 0x40) << 8) & 0xff00);
    address.address = ((u32 *)d_021D9E40)[0x264/4];
    start = OS_GetTick() / 0x7fd88;
    for (;;) {
        result = func_0215F480(((u32 *)d_021D9E40)[0x26c/4], &address);
        if (result >= 0) break;
        if (result == -26) {
            if (((u32 *)d_021D9E40)[0x244/4] != 0 && (int)((OS_GetTick() / 0x7fd88) - start) >= (int)((u32 *)d_021D9E40)[0x244/4]) {
                ((u32 *)d_021D9E40)[0x250/4] = 10;
                return 0;
            }
        } else {
            if (result == -30) break;
            ((u32 *)d_021D9E40)[0x250/4] = 7;
            return 0;
        }
        func_021D7CAC();
        if (((u32 *)d_021D9E40)[0x268/4] == 1) {
            ((u32 *)d_021D9E40)[0x250/4] = 13;
            func_021D7CC0();
            return 0;
        }
        func_021D7CC0();
        func_021D8438(1);
    }
    return 1;
}






int func_021D80E0(void)
{
    int start, count = 0, length, result;
    start = OS_GetTick() / 0x7fd88;
    for (;;) {
        length = ((u32 *)&d_021D9E40)[0x254/4] - count;
        if (length > (int)((u32 *)&d_021D9E40)[0x254/4]) length = ((u32 *)&d_021D9E40)[0x254/4];
        result = func_0215F590(((u32 *)&d_021D9E40)[0x26c/4], (char *)((u32 *)&d_021D9E40)[0x258/4] + count, length, 0);
        if (result != -6) {
            if (result < 0) {
                ((u32 *)&d_021D9E40)[0x250/4] = 11;
                return 0;
            }
            count += result;
            if (count == ((u32 *)&d_021D9E40)[0x254/4]) break;
        }
        if (((u32 *)&d_021D9E40)[0x248/4] != 0 && (int)((OS_GetTick() / 0x7fd88) - start) >= (int)((u32 *)&d_021D9E40)[0x248/4]) {
            ((u32 *)&d_021D9E40)[0x250/4] = 11;
            return 0;
        }
        func_021D7CAC();
        if (((u32 *)&d_021D9E40)[0x268/4] == 1) {
            ((u32 *)&d_021D9E40)[0x250/4] = 13;
            func_021D7CC0();
            return 0;
        }
        func_021D7CC0();
        func_021D8438(1);
    }
    return 1;
}






void func_021D81EC(void *a0)
{
    int count;
    for (;;) {
        count = ((u32 *)&d_021D9E40)[0x410/4];
        func_021D7CAC();
        if (!((u32 *)&d_021D9E40)[0x414/4]) {
            ((u32 *)&d_021D9E40)[0x40c/4] = func_0215F4DC(((u32 *)&d_021D9E40)[0x26c/4], (char *)((u32 *)&d_021D9E40)[0x260/4] + count, ((u32 *)&d_021D9E40)[0x25c/4] - count, 0);
            ((u32 *)&d_021D9E40)[0x414/4] = 1;
        }
        func_021D7CC0();
        func_021D8438(1);
    }
}






int func_021D824C(void)
{
    u32 count = 0;
    int zero = 0;
    u32 word = -1;
    int start;
    int r;
    u64 t0;
    int ret = 0;

    t0 = OS_GetTick();
    func_020853C0(d_021DA18C, func_021D81EC, 0, ((u8 *)&d_021D9E40b), 0x800, ((u32 *)&d_021D9E40)[0x270 / 4]);
    ((u32 *)&d_021D9E40)[0x40C / 4] = -6;
    ((u32 *)&d_021D9E40)[0x410 / 4] = 0;
    ((u32 *)&d_021D9E40)[0x414 / 4] = 0;
    func_02085868(d_021DA18C);
    start = t0 / 0x7fd88;
    for (;;) {
        if (((u32 *)&d_021D9E40)[0x24C / 4] != 0 && (int)((OS_GetTick() / 0x7fd88) - start) >= (int)((u32 *)&d_021D9E40)[0x24C / 4]) {
            ((u32 *)&d_021D9E40)[0x250 / 4] = 12;
            func_020855BC(d_021DA18C);
            return ret;
        }
        if (((u32 *)&d_021D9E40)[0x414 / 4] == 0) {
            continue;
        }
        r = ((u32 *)&d_021D9E40)[0x40C / 4];
        if (r != -6) {
            if (r <= 0) {
                ((u32 *)&d_021D9E40)[0x250 / 4] = 9;
                func_020855BC(d_021DA18C);
                return 0;
            }
            count += r;
            if (count >= 4 && word == -1) {
                u8 *h = (u8 *)&word;
                u8 *q = (u8 *)((u32 *)&d_021D9E40)[0x260 / 4];
                h[0] = q[0]; h[1] = q[1]; h[2] = q[2]; h[3] = q[3];
            }
            if (count == word) {
                if (word != -1) {
                    ((u32 *)&d_021D9E40)[0x25C / 4] = word - 4;
                    break;
                }
            }
            ((u32 *)&d_021D9E40)[0x410 / 4] = count;
        }
        func_021D7CAC();
        if (((u32 *)&d_021D9E40)[0x268 / 4] == 1) {
            ((u32 *)&d_021D9E40)[0x250 / 4] = 13;
            func_021D7CC0();
            func_020855BC(d_021DA18C);
            return 0;
        }
        func_021D7CC0();
        ((u32 *)&d_021D9E40)[0x414 / 4] = zero;
        func_021D8438(1);
    }
    func_020855BC(d_021DA18C);
    return 1;
}








/*
 * ARM tail call: ldr ip, =target; bx ip (the form mwcc emits, as in ov009 DWCi_ProcessMatchSynPacketSub.c).
 */
void func_021D8438(int msec)
{
    func_02085A38(msec);
}








#pragma opt_propagation off







int func_021D8444(void)
{
    u8 buf[0x174];
    int b, a;
    int r;

    if (D(0x138) == 1)
        return 1;
    if (func_02167FA8((char *)d_021D8D30, buf) == 0) {
        D(0x250) = 0xE;
        return 0;
    }
    for (;;) {
        r = func_02168040();
        if (r == 3) {
            Sav *t = (Sav *)(d_021D9E40 + 6);
            *t = *(Sav *)(buf + 0x45);
            *(Blob *)(*(char **)&D(0x258) + 8) = *(Blob *)d_021D9E40;
            D(0x138) = 1;
            return 1;
        }
        if (r == 4) {
            func_02059E38(&a, &b);
            D(0x250) = 0xE;
            return 0;
        }
        if (r == 5) {
            D(0x250) = 0xE;
            return 0;
        }
        func_021D7CAC();
        if (D(0x268) == 1) {
            D(0x250) = 0xD;
            func_021D7CC0();
            return 0;
        }
        func_021D7CC0();
        func_021D8438(1);
    }
}







#pragma opt_propagation reset







void func_021D8588(void){}








/*
 * ARM tail call: ldr ip, =target; bx ip.
 */
void func_021D858C(void)
{
    func_021D8B44();
}








/*
 * Addresses are Black-image addresses.
 */
void func_021D8598(int a, int b, int c)
{
    func_021D7770(b, c, a);
}






void func_021D85B4(void)
{
    func_021D770C();
}




unsigned func_021D85C0(void) {unsigned v;func_021D7CAC();v=func_021D7BCC();func_021D7CC0();return v;}



int func_021D85DC(void)
{
    return func_021D7C48();
}








char *func_021D85E8(void)
{
    return func_021D7BDC();
}









int func_021D85F4(void)
{
    return func_021D7C14();
}









/*
 * ARM tail call: ldr ip, =target; bx ip.
 */
int func_021D8600(int n)
{
    return func_021D89EC(n);
}








int func_021D860C(const Packet_021D860C *p, int n) {
 Packet_021D860C copy;
 copy = *p;
 return func_021D7A10(0x5208, &copy, n, -1);
}








int func_021D8654(int value, int n) {
 Packet_021D8654 p;
 p.a = 0; p.b = 0; p.value = value;
 return func_021D7A10(0x5209, &p, n, -1);
}








int func_021D8694(const Data_021D8694 *data, const void *bytes, int length, int n) {
 Packet_021D8694 p={0};
 if (length > 256) return 0;
 p.data = *data;
 p.length = length;
 func_02092344(p.bytes, bytes, length);
 return func_021D7A10(0x55f0, &p, n, -1);
}








/*
 * lever: The source Data pointer is non-const; const swaps the initial
 * strh lr,[sp] and mov r4,r1 (six concrete bytes differ).
 */
int func_021D8754(Data_021D8754 *data, int n) {
 Packet_021D8754 p;
 p.a = 0;
 p.data = *data;
 p.a = 0; p.b = 0;
 return func_021D7A10(0x55f1, &p, n, -1);
}








int func_021D879C(int value, int n) {
 Packet_021D879C p = {0};
 p.value = value;
 p.a = 1; p.tail[1] = 0; p.tail[2] = 0; p.b = 0;
 return func_021D7A10(0x55f1, &p, n, -1);
}








int func_021D87FC(int value, int n) {
 Packet_021D87FC p = {0};
 p.value = value;
 p.a = 3; p.tail[1] = 0; p.tail[2] = 0; p.b = 0;
 return func_021D7A10(0x55f1, &p, n, -1);
}








int func_021D885C(int value, int n) {
 Packet_021D885C p = {0};
 p.value = value;
 p.a = 2; p.tail[1] = 0; p.tail[2] = 0; p.b = 0;
 return func_021D7A10(0x55f1, &p, n, -1);
}







int func_021D88BC(u32 a, u32 b, u32 c, u32 n)
{
    Triple p;
    p.a=a; p.b=b; p.c=c;
    return func_021D7A10(0x55f2, &p, n, -1);
}







int func_021D88F0(u32 a, u32 b, u32 n)
{
    Pair p;
    p.a=a; p.b=b;
    return func_021D7A10(0x55f3, &p, n, -1);
}







int func_021D891C(int n)
{
    int size;
    switch (n) {
    case 0: size = 0x400; break;
    case 0x5208: size = 0x230; break;
    case 0x5209: size = 12; break;
    case 0x55f0: size = 0x19a8; break;
    case 0x55f1: size = 28; break;
    case 0x55f2: size = 12; break;
    case 0x55f3: size = 8; break;
    default: return -1;
    }
    return size + 0x140;
}







int func_021D89EC(int n)
{
    Table table = d_021D8CD0;
    int size;
    int i;
    int got;
    switch (n) {
    case -1:
        size = -1;
        for (i = 0; ; i++) {
            if (table.words[i] == -1) break;
            got = func_021D89EC(table.words[i]);
            if (got > size) size = got;
        }
        if (size == -1) return -1;
        break;
    case 0: size = 0x400; break;
    case 0x5208: size = 8; break;
    case 0x5209: size = 0xb30; break;
    case 0x55f0: size = 8; break;
    case 0x55f1: size = 0x1864; break;
    case 0x55f2: size = 0x18b0; break;
    case 0x55f3: size = 0; break;
    default: return -1;
    }
    return size + 8;
}







/*
 * extent: eight-byte leaf ends at the handed lead 0x021D8B44.
 */
int func_021D8B3C(void) { return 0; }






void func_021D8B44(void)
{
    func_02088168((u32 *)d_021DAA8C);
    func_02162248(d_021DAA8C, 32);
    if (d_021DAA88) return;
    MI_CpuFill8(d_021DAAAC, 0, 0x830);
    *(u32 *)(d_021DAAAC + 0x800) = 0;
    func_021D8BC0((u32)d_021DAAAC);
    func_021D8BF8((int)((void *)d_021D8D38), 1);
    func_021D8BE4((int)func_021D8B3C);
}






void func_021D8BC0(u32 value)
{
    if (value != 0) d_021DAA88 = (u8 *)value;
    else d_021DAA88 = (u8 *)&d_021DAAAC;
}





void func_021D8BE4(int a)
{
    *(unsigned int *)(d_021DAA88 + 0x810) = a;
}




/*
 * Resolved: the ov121 region hint on the data symbol was contested by the
 * other overlays in the window; un-hinted, sole-ref/data picks the unique
 * overlay start, so the ABS32 pool relocation resolves.
 *
 * Addresses are Black-image addresses.
 */
void func_021D8BF8(int a, int b)
{
    *(unsigned int *)(d_021DAA88 + 0x814) = a;
    *(unsigned int *)(d_021DAA88 + 0x818) = b;
}


void func_021D8C14(const char *s, u8 *p)
{
    func_02082D44(d_021DAA88, p, 0x830);
    if (s) {
        *(char * *)&((struct Obj14013 *)p)->f800 = func_021D7C7C(func_0208CC78(s) + 1);
        func_0208CADC(*(char * *)&((struct Obj14013 *)p)->f800, s);
    }
}
