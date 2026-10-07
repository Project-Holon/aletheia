/*
 * file:     wifibattlematch_net_p02.c
 * unit:     yes
 * function: func_021D458C, func_021D4608, func_021D4730
 * address:  0x021D458C
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
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021DA36C 0x021DA36C thumb ov175
 *   func_021D51BC 0x021D51BC thumb ov175
 *   func_021D5E24 0x021D5E24 thumb ov175
 *   func_021D54E8 0x021D54E8 thumb ov175
 *   func_021D6000 0x021D6000 thumb ov175
 *   func_021E7E0C 0x021E7E0C thumb ov177
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021D6550 0x021D6550 thumb ov175
 *   func_021D65DC 0x021D65DC thumb ov175
 *   func_021D65C8 0x021D65C8 thumb ov175
 *   func_021D57BC 0x021D57BC thumb ov175
 *   func_021D61CC 0x021D61CC thumb ov175
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_02012EBC 0x02012EBC thumb
 *   func_02009448 0x02009448 thumb
 *   func_020092EC 0x020092EC thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021DC738 0x021DC738 thumb ov175
 *   func_021DC77C 0x021DC77C thumb ov175
 *   func_021DC8A0 0x021DC8A0 thumb ov175
 *   func_021D61A4 0x021D61A4 thumb ov175
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021D63DC 0x021D63DC thumb ov175
 *   func_021D6788 0x021D6788 thumb ov175
 *   func_021D61F0 0x021D61F0 thumb ov175
 *   func_021D679C 0x021D679C thumb ov175
 *   func_021D495C 0x021D495C thumb ov175
 */
struct Big;
struct Sub02009448Obj;
struct Sub02009210Obj;
typedef unsigned int   u32;

typedef unsigned char u8;

extern void func_021E8AA0(int *p, int v);
extern void func_021DA36C(void *);
extern void func_021D51BC(unsigned sys, int *state, char *p);
extern void func_021D5E24(unsigned sys, int *state, char *p);
extern void func_021D54E8(unsigned,int *,int *);
extern void func_021D6000(unsigned,int *,int *);
extern void func_021E7E0C(void **, int);
extern void func_021E8738(int *, int, int, int);
extern void func_021E8AB4(u32, u32);
extern void func_021D6550(u32 *, int);
extern int func_021D65DC(char *);
extern void func_021D65C8(char *);
extern void func_021D57BC(unsigned sys, int *state, int *p);
extern void func_021D61CC(void *a, u32 **pp, char *p);
extern int func_021E8844(const int *);
extern void func_021E8AB8(u32);
extern void *func_02012EBC(struct Big *);
extern struct Sub02009448Obj *func_02009448(void *);
extern u8 func_020092EC(const struct Sub02009210Obj *);
extern void func_02082BCC(void *, int, int);
extern void func_021DC738(char *, unsigned);
extern int func_021DC77C(u8 *p);
extern void func_021DC8A0(char *, void *);
extern void func_021D61A4(void *obj, int unused, u8 *p);
extern int func_021D9F04(char *, void *, void *);
extern void func_021D63DC(char *);
extern void func_021D6788(char *, void *);
extern void func_021D61F0(u32 sys, int *state, char *p);
extern u32 func_021D679C(char *);
extern void func_021D495C(u32 sys, int *state, u32 *p);
void func_021D458C(unsigned sys,int *state,int *p);
void func_021D4608(u32 sys, int *state, u32 *p);
void func_021D4730(u32 sys, int *state, u32 *p);

void func_021D458C(unsigned sys,int *state,int *p)
{
    int *q=(int *)p[16];
    switch(q[3]) {
    case 0: func_021E8AA0((int *)sys,(int)func_021D4608); break;
    case 2:
        func_021DA36C((void *)p[12]);
    case 1:
        if(q[0]==0) func_021E8AA0((int *)sys,(int)func_021D51BC);
        else if(q[0]==1) func_021E8AA0((int *)sys,(int)func_021D5E24);
        break;
    case 3:
        if(q[0]==0) func_021E8AA0((int *)sys,(int)func_021D54E8);
        else if(q[0]==1) func_021E8AA0((int *)sys,(int)func_021D6000);
        break;
    }
}

void func_021D4608(u32 sys, int *state, u32 *p)
{
    u32 *ctx = (u32 *)p[16];
    int result;
    switch (*state) {
    case 0: func_021E7E0C((void **)p[8], 0); *state = 1; break;
    case 1:
        func_021E8738((int *)p[9], p[4], 25, 1);
        *state = 7; func_021E8AB4(sys, 2); break;
    case 2: func_021D6550(p, 1); *state = 3; break;
    case 3:
        result = func_021D65DC((char *)p);
        if (result != -1) {
            func_021D65C8((char *)p);
            switch (result) {
            case 0: ctx[0] = 1; func_021E8AA0((int *)sys, (int)func_021D57BC); break;
            case 1: ctx[0] = 0; func_021E8AA0((int *)sys, (int)func_021D4730); break;
            case 2: ctx[0] = 3; *state = 4; break;
            }
        }
        break;
    case 4:
        func_021E8738((int *)p[9], p[4], 30, 1);
        *state = 7; func_021E8AB4(sys, 5); break;
    case 5: func_021D6550(p, 0); *state = 6; break;
    case 6:
        result = func_021D65DC((char *)p);
        if (result != -1) {
            func_021D65C8((char *)p);
            switch (result) {
            case 0: ctx[1] = 0; func_021E8AA0((int *)sys, (int)func_021D61CC); break;
            case 1: *state = 1; break;
            }
        }
        break;
    case 7: if (func_021E8844((int *)p[9])) func_021E8AB8(sys); break;
    }
}

void func_021D4730(u32 sys, int *state, u32 *p)
{
    u32 *ctx = (u32 *)p[16];
    u32 result;
    switch (*state) {
    case 0:
        if (func_020092EC((const struct Sub02009210Obj *)func_02009448(func_02012EBC((struct Big *)*(u32 *)ctx[2])))) *state = 1;
        else *state = 6;
        break;
    case 1: func_021E8738((int *)p[9], p[4], 41, 1); *state = 14; func_021E8AB4(sys, 2); break;
    case 2: func_021E8738((int *)p[9], p[4], 24, 2); *state = 14; func_021E8AB4(sys, 3); break;
    case 3: func_02082BCC((void *)ctx[12], 0, 8); func_021DC738((char *)p[12], 87); *state = 4; break;
    case 4:
        switch (func_021DC77C((u8 *)p[12])) {
        case 0: break;
        case 1: func_021DC8A0((char *)p[12], (void *)((u32 *)p[16])[12]); *state = 5; break;
        case 3: func_02082BCC((void *)((u32 *)p[16])[12], 0, 8); func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        case 2:
            switch (func_021D9F04((char *)p[12], 0, 0)) {
            case 2: func_021E8AA0((int *)sys, (int)func_021D61A4); break;
            case 1: func_021D63DC((char *)p); func_021E8AA0((int *)sys, (int)func_021D4608); break;
            }
            break;
        }
        break;
    case 5: if (((u8 *)ctx[12])[6]) *state = 9; else *state = 6; break;
    case 6: func_021E8738((int *)p[9], p[4], 55, 1); *state = 14; func_021E8AB4(sys, 12); break;
    case 9:
        func_021D6788((char *)p, func_021D61F0); *state = 10;
        switch (func_021D9F04((char *)p[12], 0, 0)) {
        case 1: func_021D63DC((char *)p); func_021E8AA0((int *)sys, (int)func_021D4608); break;
        case 2: func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
        break;
    case 10:
        result = func_021D679C((char *)p);
        if (result == 0) *state = 13;
        else if (result == 1) *state = 11;
        else if (result == 3) func_021E8AA0((int *)sys, (int)func_021D61A4);
        if (result != 0xffff) {
            switch (func_021D9F04((char *)p[12], 0, 0)) {
            case 1: func_021D63DC((char *)p); func_021E8AA0((int *)sys, (int)func_021D4608); break;
            case 2: func_021E8AA0((int *)sys, (int)func_021D61A4); break;
            }
        }
        break;
    case 11: func_021E8738((int *)p[9], p[4], 120, 1); *state = 14; func_021E8AB4(sys, 12); break;
    case 12: func_021E8AA0((int *)sys, (int)func_021D61CC); break;
    case 13: func_021E8AA0((int *)sys, (int)func_021D495C); break;
    case 14: if (func_021E8844((int *)p[9])) func_021E8AB8(sys); break;
    }
}
