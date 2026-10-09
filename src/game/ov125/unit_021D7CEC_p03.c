/*
 * file:     unit_021D7CEC_p03.c
 * unit:     yes
 * function: func_021D85E8, func_021D85F4, func_021D8600, func_021D860C, func_021D8654, func_021D8694, func_021D8754, func_021D879C, func_021D87FC, func_021D885C, func_021D88BC, func_021D88F0, func_021D891C, func_021D89EC, func_021D8B3C, func_021D8B44, func_021D8BC0, func_021D8BE4, func_021D8BF8, func_021D8C14
 * address:  0x021D85E8
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
 *   func_021D7BDC  0x021D7BDC  arm ov125
 *   func_021D7C14  0x021D7C14  arm ov125
 *   func_021D7A10 0x021D7A10 arm ov125
 *   d_021D8CD0 0x021D8CD0 data a4
 *   func_02088168 0x02088168 arm
 *   func_02162248 0x02162248 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021DAA8C 0x021DAA8C data a4
 *   d_021DAA88 0x021DAA88 data a4
 *   d_021DAAAC 0x021DAAAC data a4
 *   d_021D8D38 0x021D8D38 data a4
 *   func_02082D44 0x02082D44 arm
 *   func_0208CC78 0x0208CC78 arm
 *   func_021D7C7C 0x021D7C7C arm ov125
 *   func_0208CADC 0x0208CADC arm
 */
#include "../../matched/include/Obj14013.h"

typedef struct { unsigned words[0x230/4]; } Packet_021D860C;

typedef struct { unsigned short a,b; long long value; } Packet_021D8654;

typedef struct { unsigned words[0x18a4/4]; } Data_021D8694;

typedef struct { Data_021D8694 data; int length; char bytes[256]; } Packet_021D8694;

typedef struct { unsigned words[4]; } Data_021D8754;

typedef struct { unsigned short a,b; Data_021D8754 data; unsigned tail[2]; } Packet_021D8754;

typedef struct { unsigned short a,b; unsigned words[2]; int value; unsigned tail[3]; } Packet_021D879C;

typedef struct { unsigned short a,b; unsigned words[2]; int value; unsigned tail[3]; } Packet_021D87FC;

typedef struct { unsigned short a,b; unsigned words[2]; int value; unsigned tail[3]; } Packet_021D885C;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct {int a,b,c;} Triple;

typedef struct {int a,b;} Pair;

typedef struct { int words[8]; } Table;

extern char *func_021D7BDC(void);
extern int func_021D7C14(void);
extern int func_021D7A10(int id, void *buf, int x, int sz);
extern void *func_02092344(void *dest, const void *src, unsigned int n);
extern void func_02088168(u32 *buffer);
extern void func_02162248(void *, u32);
extern void func_02082BCC(void *, u32, u32);
extern void func_02082D44(const void *, void *, u32);
extern u32 func_0208CC78(const char *);
extern char *func_021D7C7C(u32);
extern char *func_0208CADC(char *destp, const char *srcp);
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
extern const Table d_021D8CD0;
extern u8 d_021DAA8C[];
extern u8 d_021DAAAC[];
extern u8 *d_021DAA88;
extern const u32 d_021D8D38[];







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
    func_02082BCC(d_021DAAAC, 0, 0x830);
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
