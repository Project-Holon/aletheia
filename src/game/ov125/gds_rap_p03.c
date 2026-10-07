/*
 * file:     gds_rap_p03.c
 * unit:     yes
 * function: func_021D73E0, func_021D73F0, func_021D7414, func_021D74B4, func_021D74D8, func_021D7520, func_021D7540, func_021D75E8, func_021D7630, func_021D76A8, func_021D76D8, func_021D7700
 * address:  0x021D73E0
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D85E8 0x021D85E8 arm ov125
 *   func_02034714 0x02034714 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F1FC 0x0203F1FC arm
 *   d_021D8D2C 0x021D8D2C data a4
 *   d_0214616C 0x0214616C data a4
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200725C 0x0200725C thumb
 *   func_020073D8 0x020073D8 thumb
 *   func_0200B448 0x0200B448 thumb
 *   func_02012E4C 0x02012E4C thumb
 *   func_02012E7C 0x02012E7C thumb
 *   func_020072A4 0x020072A4 thumb
 */
#include "../../matched/include/G_BattleRec.h"
#include "../../matched/include/Obj14011.h"

struct BattleRec;
struct Ctrl;
struct Big;
struct Sub020072A4Ctrl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct { u32 w[49]; } Rec;

extern char *func_021D85E8(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02082BCC(void *, int, u32);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_0200B908(void *a, u32 b, u32 c);
extern u32 func_0200B67C(void *a, struct BattleRec *b, u32 c, u16 *state, u16 e);
extern void *func_02012EBC(struct Big *p);
extern unsigned int func_0200725C(struct Ctrl *,unsigned int,unsigned char);
extern void *func_020073D8(void *,unsigned int,unsigned int);
extern void func_0200B448(void *);
extern void func_02012E4C(unsigned char *,unsigned int);
extern int func_02012E7C(char *,int);
extern void func_020072A4(struct Sub020072A4Ctrl *,unsigned int);
unsigned long long func_021D73E0(char *a0);
int func_021D73F0(char *p, const unsigned short *s);
int func_021D7414(char *unused, char *dst, int n);
int func_021D74B4(char *p, const unsigned short *s);
int func_021D74D8(void *unused, char **out);
int func_021D7520(char *p, const unsigned short *s);
int func_021D7540(void *a, int x, int mode, u16 *state, u16 *b, u16 c);
void func_021D75C0(void);
int func_021D75E8(int a, int x, int y, u16 *state, int b, u16 c);
int func_021D7630(void *a, int x, u16 *state, u16 *b, u16 c);
void func_021D76A8(unsigned char *p,unsigned char heap,unsigned int id);
int func_021D76D8(char *p,int id);
char *func_021D7700(void);
extern char d_021D8D2C[];
extern struct BattleRec *d_0214616C;

unsigned long long func_021D73E0(char *a0) { int *p=(int *)func_021D85E8(); return *(unsigned long long *)(p+1); }

int func_021D73F0(char *p, const unsigned short *s) { int r=0; switch (s[1]) { case 0: r=1; break; case 1: case 2: case 3: case 4: break; default: break; } return r; }


/*
 * note: 2026-10-05 (D4-14): the xor/orr equality is a 64-bit compare; written as u64 loads, EXACT.
 */
int func_021D7414(char *unused, char *dst, int n)
{
    int *g = (int *)func_021D85E8();
    int *hdr = g + 1;
    char *base;
    int cnt;
    int i;

    cnt = hdr[0];
    if (cnt > n) {
        cnt = n;
        func_02034714(d_021D8D2C, 0, d_021D8D2C);
    }
    func_02082BCC(dst, 0, n * 0xC4);
    i = 0;
    base = (char *)hdr + 4;
    for (i = 0; i < cnt; i++) {
        char *e = base + i * 0xD0;
        u64 id = *(u64 *)(e + 4);
        if (*(u64 *)(e + 0xC4) != id) {
            *(u64 *)(e + 0xC4) = id;
            *(u16 *)(e + 0xCC) = func_0203F1FC((const u8 *)(e + 0x8C), 0x38);
        }
        *(Rec *)(dst + i * 0xC4) = *(Rec *)(e + 0xC);
    }
    return cnt;
}

int func_021D74B4(char *p, const unsigned short *s) { int r=0; switch (s[1]) { case 0: r=1; break; case 1: case 2: case 3: case 4: break; default: break; } return r; }

int func_021D74D8(void *unused, char **out)
{
    char *p = (char *)func_021D85E8();
    char *s = p + 4;
    u64 id;

    *out = s + 0xC;
    id = *(u64 *)(p + 8);
    if (*(u64 *)(s + 0xC4) != id) {
        *(u64 *)(s + 0xC4) = id;
        *(u16 *)(*out + 0xC0) = func_0203F1FC((u8 *)(*out + 0x80), 0x38);
    }
    return *(int *)(p + 8);
}

int func_021D7520(char *p, const unsigned short *s) { int r=0; switch (s[1]) { case 0: r=1; break; case 1: case 2: case 3: break; default: break; } return r; }

int func_021D7540(void *a, int x, int mode, u16 *state, u16 *b, u16 c)
{
    unsigned int value;
    switch (*state) {
    case 0:
        if (mode == 1) {
            *(unsigned char *)(((char *)d_0214616C) + 0xaa) = mode;
            *(u16 *)(((char *)d_0214616C) + 0xa8) = 57985;
            *(u16 *)(((char *)d_0214616C) + 0xc0) = func_0203F1FC((const u8 *)(((char *)d_0214616C) + 0x80), 56);
        }
        value = *(u16 *)(((char *)d_0214616C) + 0x18a0);
        func_0200B908(((char *)d_0214616C) + 0xc4, 0x17dc, value + ((value ^ 0xffff) << 16));
        ++*state;
        break;
    case 1:
        return func_0200B67C(a, (struct BattleRec *)((char *)d_0214616C), x, b, c);
    }
    return 0;
}

void func_021D75C0(void)
{
    unsigned int value;
    value = *(u16 *)(((char *)d_0214616C) + 0x18a0);
    func_0200B908(((char *)d_0214616C) + 0xc4, 0x17dc, value + ((value ^ 0xffff) << 16));
}

int func_021D75E8(int a, int x, int y, u16 *state, int b, u16 c)
{
    char *p;
    switch (*state) {
    case 0:
        p = ((char *)d_0214616C);
        ((struct Obj14011 *)p)->fB8 = x;
        ((struct Obj14011 *)p)->fBC = y;
        ++*state;
        break;
    case 1:
        return func_0200B67C((void *)a, (struct BattleRec *)((char *)d_0214616C), 0, (u16 *)b, c);
    }
    return 0;
}

int func_021D7630(void *a, int x, u16 *state, u16 *b, u16 c)
{
    unsigned int value;
    switch (*state) {
    case 0:
        *(unsigned char *)(((char *)d_0214616C) + 0xaa) = 1;
        *(u16 *)(((char *)d_0214616C) + 0xa8) = 57985;
        *(u16 *)(((char *)d_0214616C) + 0xc0) = func_0203F1FC((const u8 *)(((char *)d_0214616C) + 0x80), 56);
        value = *(u16 *)(((char *)d_0214616C) + 0x18a0);
        func_0200B908(((char *)d_0214616C) + 0xc4, 0x17dc, value + ((value ^ 0xffff) << 16));
        ++*state;
        break;
    case 1:
        return func_0200B67C(a, (struct BattleRec *)((char *)d_0214616C), x, b, c);
    }
    return 0;
}

void func_021D76A8(unsigned char *p,unsigned char heap,unsigned int id) {void *s=func_02012EBC((struct Big *)p); func_0200725C(s,id,heap); func_0200B448(func_020073D8(s,id,0)); func_02012E4C(p,id);}

int func_021D76D8(char *p,int id) {void *s=func_02012EBC((struct Big *)p); int r=func_02012E7C(p,id); if(r==2 || r==3) func_020072A4(s,id); return r;}

char *func_021D7700(void) { return ((char *)d_0214616C); }
