/*
 * file:     wifibattlematch_net_p04.c
 * unit:     yes
 * function: func_021D56D4, func_021D57BC, func_021D5908
 * address:  0x021D56D4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021DBC04 0x021DBC04 thumb ov175
 *   func_021DBDAC 0x021DBDAC thumb ov175
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021DA36C 0x021DA36C thumb ov175
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021D61CC 0x021D61CC thumb ov175
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021D62A4 0x021D62A4 thumb ov175
 *   func_021D63B0 0x021D63B0 thumb ov175
 *   func_021D6788 0x021D6788 thumb ov175
 *   func_021D679C 0x021D679C thumb ov175
 *   func_021D63DC 0x021D63DC thumb ov175
 *   func_021D61F0 0x021D61F0 thumb ov175
 *   func_021D4608 0x021D4608 thumb ov175
 *   func_021D61A4 0x021D61A4 thumb ov175
 *   func_021D6854 0x021D6854 thumb ov175
 *   func_021D60E0 0x021D60E0 thumb ov175
 *   func_021D6048 0x021D6048 thumb ov175
 *   func_021D6724 0x021D6724 thumb ov175
 *   func_021E7E0C 0x021E7E0C thumb ov177
 *   func_021D65F0 0x021D65F0 thumb ov175
 *   func_021DA0D4 0x021DA0D4 thumb ov175
 *   func_021D6954 0x021D6954 thumb ov175
 *   func_021DA1E4 0x021DA1E4 thumb ov175
 *   func_021D9ED4 0x021D9ED4 thumb ov175
 *   func_021D9EEC 0x021D9EEC thumb ov175
 *   func_021DC1A0 0x021DC1A0 thumb ov175
 *   func_021DC1E4 0x021DC1E4 thumb ov175
 *   func_0201A918 0x0201A918 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_02045A98 0x02045A98 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045A38 0x02045A38 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02025BEC 0x02025BEC thumb
 *   func_020245D4 0x020245D4 thumb
 *   func_020242A4 0x020242A4 thumb
 *   func_021D67BC 0x021D67BC thumb ov175
 *   func_021DCA28 0x021DCA28 thumb ov175
 *   func_021DCAEC 0x021DCAEC thumb ov175
 *   func_021DA45C 0x021DA45C thumb ov175
 *   func_020061E4 0x020061E4 thumb
 *   func_021D65C8 0x021D65C8 thumb ov175
 *   func_021D63F8 0x021D63F8 thumb ov175
 *   func_02040588 0x02040588 arm
 *   func_021D6460 0x021D6460 thumb ov175
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   func_021DA434 0x021DA434 thumb ov175
 */
#include "../../matched/include/Obj08273.h"

#define P(k) (*(int *)(p + (k)))
#define Q(k) (*(int *)(q + (k)))
#define TIMER (*(u32_021D5908 *)(p + 0xe0))
#define TIMEOUT (*(u32_021D5908 *)(p + 0xe8))
struct Record;
struct MsgBank;
struct U16Vec;
struct MsgRec;
struct T;
struct Rec;
typedef unsigned char u8;

typedef unsigned int   u32_021D56D4;

typedef unsigned int u32_021D57BC;

typedef unsigned long u32_021D5908;

typedef unsigned short u16;

extern void func_021E8738(int *, int, int, int);
extern void func_021E8AB4(unsigned, unsigned);
extern int func_02012DAC(int);
extern int func_02012DD0(u8 *);
extern void func_021DBC04(u8 *p, u32_021D56D4 mode, struct Record *src);
extern int func_021DBDAC(char *);
extern int func_021D9F04(char *, void *, void *);
extern void func_021DA36C(int);
extern void func_021E8AA0(int *, int);
extern void func_021D61CC(void *, unsigned **, char *);
extern int func_021E8844(const int *);
extern void func_021E8AB8(unsigned);
extern void func_021D62A4(u32_021D57BC *p, u32_021D57BC mode);
extern unsigned long func_021D63B0(char *);
extern void func_021D6788(char *, void *);
extern unsigned long func_021D679C(char *);
extern void func_021D63DC(char *);
extern void func_021D61F0(u32_021D57BC sys, int *state, char *p);
extern void func_021D4608(u32_021D57BC sys, int *state, u32_021D57BC *p);
extern void func_021D61A4(void *obj, int unused, u8 *p);
extern int func_021D6854(char *, int, int);
extern void func_021D60E0(u32_021D5908 sys, int *state, u32_021D5908 *p);
extern void func_021D6048(unsigned sys, int *state, int *p);
extern void func_021D6724(u32_021D5908 *, u32_021D5908 *);
extern void func_021E7E0C(void **, int);
extern void func_021D65F0(u32_021D5908 *, u32_021D5908 *);
extern void func_021DA0D4(char *obj, int mode, int extra, int group, int *rec);
extern void func_021D6954(char *);
extern int func_021DA1E4(char *obj);
extern void func_021D9ED4(char *, u32_021D5908);
extern int func_021D9EEC(char *);
extern u32_021D5908 func_021DC1A0(char *obj, u32_021D5908 data);
extern u32_021D5908 func_021DC1E4(char *, char **);
extern int func_0201A918(void);
extern void func_02082D44(const void *, void *, u32_021D5908);
extern u16 func_02045A98(void);
extern struct MsgBank *func_02045B38(u32_021D5908, u32_021D5908, u32_021D5908, u32_021D5908);
extern void *func_02045EC0(struct MsgBank *, u32_021D5908);
extern void func_02045A38(struct U16Vec *, u16 *, unsigned int);
extern void func_02045808(struct U16Vec *);
extern u32_021D5908 func_02045C04(struct Rec *rec);
extern unsigned int func_02025BEC(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020245D4(struct T *, unsigned int);
extern void func_020242A4(void *, unsigned int);
extern int func_021D67BC(char *, u16);
extern void func_021DCA28(char *, u32_021D5908, u16);
extern int func_021DCAEC(char *, int *);
extern u32_021D5908 func_021DA45C(char *);
extern void func_020061E4(unsigned);
extern void func_021D65C8(char *);
extern void func_021D63F8(unsigned int *, unsigned int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern int func_021D6460(char *);
extern void func_021E8AA8(int);
extern int func_021DA434(int);
void func_021D56D4(unsigned sys, int *state, int *p);
void func_021D57BC(unsigned sys, int *state, int *p);
void func_021D5908(unsigned sys, int *state, char *p);

/*
 * The original loads p[12] before the otherwise parameterless DA36C.
 */
void func_021D56D4(unsigned sys, int *state, int *p)
{
    char *q = (char *)p[16];
    switch (*state) {
    case 0:
        func_021E8738((int *)p[9], p[4], 40, 2);
        func_021E8AB4(sys, 1);
        *state = 7;
        break;
    case 1:
        func_02012DAC(**(int * *)&((struct Obj08273 *)q)->f8);
        *state = 2;
        break;
    case 2:
        if (func_02012DD0((u8 *)**(int * *)&((struct Obj08273 *)q)->f8) == 2) *state = 3;
        break;
    case 3:
        func_021E8738((int *)p[9], p[4], 37, 2);
        *state = 7;
        func_021E8AB4(sys, 4);
        break;
    case 4:
        if (**(int * *)&((struct Obj08273 *)q)->f20 == 0) {
            func_021DBC04((u8 *)p[12], 2, 0);
            *state = 5;
        }
        break;
    case 5:
        if (func_021DBDAC((char *)p[12])) {
            **(int **)((char *)p[16] + 0x20) = 0x708;
            *state = 6;
            func_021D9F04((char *)p[12], (void *)1, 0);
        }
        break;
    case 6:
        func_021DA36C(p[12]);
        ((struct Obj08273 *)q)->f4 = 0;
        func_021E8AA0((int *)sys, (int)func_021D61CC);
        break;
    case 7:
        if (func_021E8844((int *)p[9])) func_021E8AB8(sys);
        break;
    }
}

void func_021D57BC(unsigned sys, int *state, int *p)
{
    unsigned long r;
    switch (*state) {
    case 0:
        func_021E8738((int *)p[9], p[4], 26, 1);
        func_021D62A4((u32_021D57BC *)p, 1);
        *state = 1;
        break;
    case 1:
        if (func_021D63B0((char *)p)) *state = 2;
        break;
    case 2:
        if (func_021E8844((int *)p[9])) *state = 3;
        break;
    case 3:
        func_021E8738((int *)p[9], p[4], 24, 2);
        *state = 4;
        break;
    case 4:
        func_021D6788((char *)p, func_021D61F0);
        *state = 5;
        switch (func_021D9F04((char *)p[12], 0, 0)) {
        case 1:
            func_021D63DC((char *)p);
            func_021E8AA0((int *)sys, (int)func_021D4608);
            break;
        case 2:
            func_021E8AA0((int *)sys, (int)func_021D61A4);
            break;
        }
        break;
    case 5:
        r = func_021D679C((char *)p);
        if (r == 0) func_021E8AA0((int *)sys, (int)func_021D5908);
        else if (r == 1) *state = 6;
        else if (r == 3) func_021E8AA0((int *)sys, (int)func_021D61A4);
        if (r != 0xffff) {
            switch (func_021D9F04((char *)p[12], 0, 0)) {
            case 1:
                func_021D63DC((char *)p);
                func_021E8AA0((int *)sys, (int)func_021D4608);
                break;
            case 2:
                func_021E8AA0((int *)sys, (int)func_021D61A4);
                break;
            }
        }
        break;
    case 6:
        func_021E8738((int *)p[9], p[4], 120, 1);
        *state = 7;
        break;
    case 7:
        if (func_021E8844((int *)p[9])) func_021E8AA0((int *)sys, (int)func_021D61CC);
        break;
    }
}

/*
 * DC1A0's live return is tested here; DA434/DA36C receive the context r0.
 */
void func_021D5908(unsigned sys, int *state, char *p)
{
    char *q = (char *)P(0x40);
    int timed = 0;
    int enable = 0, allow, result, i, empty, expired;
    char *incoming, *data;
    int bad;
    u32_021D5908 size;
    u32_021D5908 buf[4];
    struct MsgBank *bank;
    struct U16Vec *str;
    if (*state >= 3 && *state < 13) enable = 1;
    if (*state < 11 || *state > 12) allow = 1; else allow = 0;
    result = func_021D6854(p, enable, allow);
    if (result == 3) {
        func_021E8AA0((int *)sys, (int)func_021D60E0);
        return;
    }
    switch (*state) {
    case 0:
        func_021D6724((u32_021D5908 *)Q(0x14), (u32_021D5908 *)p); *state = 1; break;
    case 1:
        P(0xe4) = 0;
        func_021E7E0C((void **)P(0x20), 1);
        func_021E8738((int *)P(0x24), P(0x10), 33, 0);
        *state = 2; break;
    case 2:
        switch (func_021D9F04((char *)P(0x30), 0, 0)) {
        case 1:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D4608); return;
        case 2:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D61A4); return;
        }
        func_021D65F0(buf, (u32_021D5908 *)p);
        func_021DA0D4((void *)P(0x30), 3, 0, ((int *)Q(8))[1], (int *)buf);
        *state = 3; break;
    case 3:
        switch (func_021D9F04((char *)P(0x30), 0, 0)) {
        case 1:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D4608);
            func_021D6954(p); return;
        case 2:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D61A4); return;
        }
        result = func_021DA1E4((void *)P(0x30));
        if (result == 1) { TIMEOUT = 0; *state = 6; }
        else if (result == 2) *state = 2;
        break;
    case 4: case 5: break;
    case 6:
        func_021D9ED4((char *)P(0x30), 20); *state = 7; TIMEOUT = 0; break;
    case 7:
        if (func_021D9EEC((char *)P(0x30))) { TIMEOUT = 0; *state = 8; }
        timed = 1; break;
    case 8:
        if (result == 0) {
            if (func_021DC1A0((char *)P(0x30), Q(0x14))) { TIMEOUT = 0; *state = 9; }
            timed = 1;
        }
        break;
    case 9:
        if (func_021DC1E4((char *)P(0x30), &incoming)) {
            data = (char *)Q(0x18);
            size = func_0201A918() + 0xd4;
            func_02082D44(incoming, data, size);
            empty = 1;
            for (i = 0; i < 8; i++) if (((u16 *)data)[i] == func_02045A98()) empty = 0;
            if (empty) {
                bank = func_02045B38(0, 2, 0xd2, 0x8057);
                str = func_02045EC0(bank, 0x8057);
                func_02045A38(str, (u16 *)data, 8);
                func_02045808(str);
                func_02045C04((struct Rec *)bank);
            }
            if ((u8)data[0x1d] != 0 && (u8)data[0x1d] != 1) data[0x1d] = 0;
            if ((u8)data[0x1c] >= 16) {
                if ((u8)data[0x1d] == 0) data[0x1c] = 0; else data[0x1c] = 8;
            }
            if (!func_02025BEC((u8)data[0x18], (u8)data[0x19], (u8)data[0x1a])) {
                data[0x18] = 0; data[0x19] = 0;
            }
            if (!func_020245D4((struct T *)(data + 0x38), 0x8057)) func_020242A4(data + 0x38, 1);
            TIMEOUT = 0; *state = 10;
        }
        timed = 1; break;
    case 10:
        if (func_021D67BC((char *)Q(0x18), 0x57)) *state = 11;
        else {
            func_021DA36C(P(0x30));
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D5908);
        }
        break;
    case 11:
        func_021DCA28((char *)P(0x30), Q(0x18), 0x57); *state = 12; break;
    case 12:
        if (func_021DCAEC((char *)P(0x30), &bad)) {
            *(int *)((int *)P(0x40))[16] = bad; *state = 13;
        }
        switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D6048);
            func_021D6954(p); break;
        case 2:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
        break;
    case 13:
        if (result == 0) {
            func_021D9ED4((char *)P(0x30), 21); TIMEOUT = 0; *state = 14;
        }
        break;
    case 14:
        if (func_021DA45C((char *)P(0x30)) == 0 && func_021D9EEC((char *)P(0x30))) *state = 15;
        timed = 1; break;
    case 15:
        func_021D9ED4((char *)P(0x30), 22); TIMEOUT = 0; *state = 16; break;
    case 16:
        timed = 1;
        if (func_021D9EEC((char *)P(0x30))) *state = 17;
        break;
    case 17:
        func_021E7E0C((void **)P(0x20), 0);
        func_020061E4(0x63a); func_021D65C8(p);
        func_021E8738((int *)P(0x24), P(0x10), 34, 1);
        *state = 25; func_021E8AB4(sys, 18); break;
    case 18:
        if (TIMER++ > 120) {
            TIMER = 0; func_021D63F8((unsigned int *)p, Q(0x18)); func_02040588(0, 0); *state = 19;
        }
        break;
    case 19: if (func_021D6460(p)) *state = 20; break;
    case 20: if (TIMER++ > 300) { TIMER = 0; *state = 21; } break;
    case 21:
        func_02040588(0, 1); func_021E8738((int *)P(0x24), P(0x10), 36, 2);
        *state = 25; func_021E8AB4(sys, 22); break;
    case 22:
        if (TIMER++ > 60) { TIMER = 0; Q(4) = 1; func_021E8AA8(sys); }
        break;
    case 23: if (func_021DA434(P(0x30))) *state = 24; break;
    case 24: func_021DA36C(P(0x30)); *state = 1; break;
    case 25: if (func_021E8844((int *)P(0x24))) func_021E8AB8(sys); break;
    }
    if (timed) {
        expired = 0;
        if (TIMEOUT++ > 2400) { TIMEOUT = 0; expired = 1; }
        if (func_021DA45C((char *)P(0x30))) expired = 1;
        if (expired) *state = 23;
        switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D6048);
            func_021D6954(p); return;
        case 2:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
    }
}
