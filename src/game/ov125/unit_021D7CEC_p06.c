/*
 * file:     unit_021D7CEC_p06.c
 * unit:     yes
 * function: func_021D85F4, func_021D8600, func_021D860C, func_021D8654, func_021D8694, func_021D8754, func_021D879C, func_021D87FC, func_021D885C
 * address:  0x021D85F4
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
 *   func_021D7C14  0x021D7C14  arm ov125
 *   func_021D89EC  0x021D89EC  arm ov125
 *   func_021D7A10 0x021D7A10 arm ov125
 */
typedef struct { unsigned words[0x230/4]; } Packet_021D860C;

typedef struct { unsigned short a,b; long long value; } Packet_021D8654;

typedef struct { unsigned words[0x18a4/4]; } Data_021D8694;

typedef struct { Data_021D8694 data; int length; char bytes[256]; } Packet_021D8694;

typedef struct { unsigned words[4]; } Data_021D8754;

typedef struct { unsigned short a,b; Data_021D8754 data; unsigned tail[2]; } Packet_021D8754;

typedef struct { unsigned short a,b; unsigned words[2]; int value; unsigned tail[3]; } Packet_021D879C;

typedef struct { unsigned short a,b; unsigned words[2]; int value; unsigned tail[3]; } Packet_021D87FC;

typedef struct { unsigned short a,b; unsigned words[2]; int value; unsigned tail[3]; } Packet_021D885C;

extern int func_021D7C14(void);
extern int func_021D89EC(int n);
extern int func_021D7A10(int id, void *buf, int x, int sz);
extern void *func_02092344(void *dest, const void *src, unsigned int n);
int func_021D85F4(void);
int func_021D8600(int n);
int func_021D860C(const Packet_021D860C *p, int n);
int func_021D8654(int value, int n);
int func_021D8694(const Data_021D8694 *data, const void *bytes, int length, int n);
int func_021D8754(Data_021D8754 *data, int n);
int func_021D879C(int value, int n);
int func_021D87FC(int value, int n);
int func_021D885C(int value, int n);


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
