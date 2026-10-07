/*
 * file:     wifibattlematch_net_p03.c
 * unit:     yes
 * function: func_021D54E8, func_021D5560, func_021D5634
 * address:  0x021D54E8
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
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021D61A4 0x021D61A4 thumb ov175
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021D6550 0x021D6550 thumb ov175
 *   func_021D65DC 0x021D65DC thumb ov175
 *   func_021D65C8 0x021D65C8 thumb ov175
 *   func_021D495C 0x021D495C thumb ov175
 *   func_021DA36C 0x021DA36C thumb ov175
 *   func_021D56D4 0x021D56D4 thumb ov175
 */
typedef unsigned char  u8;

typedef unsigned int u32;

extern int func_021D9F04(char *ctx, void *a, void *b);
extern void func_021E8AA0(int *p, int v);
extern int func_021E8844(const int *p);
extern void func_021E8AB8(unsigned);
extern void func_021D61A4(void *obj, int unused, u8 *p);
extern void func_021E8AB4(unsigned, unsigned);
extern void func_021E8738(int *, int, int, int);
extern void func_021D6550(u32 *, int);
extern int func_021D65DC(char *);
extern void func_021D65C8(char *);
extern void func_021D495C(u32 sys, int *state, u32 *p);
extern void func_021DA36C(void *);
extern void func_021D56D4(unsigned sys, int *state, int *p);
void func_021D54E8(unsigned sys,int *state,int *p);
void func_021D5560(unsigned sys, int *state, int *p);
void func_021D5634(unsigned sys,int *state,int *p);

void func_021D54E8(unsigned sys,int *state,int *p)
{
    switch(state[0]) {
    case 0:
        switch(func_021D9F04((char *)p[12],0,(void *)1)) {
        case 0: state[0]=1; break;
        case 1: case 4: func_021E8AA0((int *)sys,(int)func_021D5560); break;
        case 2: func_021E8AA0((int *)sys,(int)func_021D61A4); break;
        case 3: break;
        }
        break;
    case 1: func_021E8AA0((int *)sys,(int)func_021D5560); break;
    case 2: if(func_021E8844((const int *)p[9])) func_021E8AB8(sys); break;
    }
}

void func_021D5560(unsigned sys, int *state, int *p)
{
    int result;
    switch (*state) {
    case 0:
        switch (func_021D9F04((char *)p[12], 0, (void *)1)) {
        case 0: case 1: case 4: *state = 1; break;
        case 2: func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        case 3: break;
        }
        break;
    case 1:
        func_021E8738((int *)p[9], p[4], 0x26, 1);
        *state = 4;
        func_021E8AB4(sys, 2);
        break;
    case 2:
        func_021D6550((u32 *)p, 0);
        *state = 3;
        break;
    case 3:
        result = func_021D65DC((char *)p);
        if (result != -1) {
            func_021D65C8((char *)p);
            switch (result) {
            case 0: func_021E8AA0((int *)sys, (int)func_021D495C); break;
            case 1: func_021E8AA0((int *)sys, (int)func_021D5634); break;
            }
        }
        break;
    case 4:
        if (func_021E8844((const int *)p[9])) func_021E8AB8(sys);
        break;
    }
}

void func_021D5634(unsigned sys,int *state,int *p)
{
    int result;
    switch(state[0]) {
    case 0:
        func_021E8738((int *)p[9],p[4],0x27,1);
        state[0]=3;
        func_021E8AB4(sys,1);
        break;
    case 1: func_021D6550((u32 *)p,0); state[0]=2; break;
    case 2:
        result=func_021D65DC((char *)p);
        if(result!=-1) {
            func_021D65C8((char *)p);
            switch(result) {
            case 0: func_021DA36C((void *)p[12]); func_021E8AA0((int *)sys,(int)func_021D56D4); break;
            case 1: func_021E8AA0((int *)sys,(int)func_021D5560); break;
            }
        }
        break;
    case 3: if(func_021E8844((const int *)p[9])) func_021E8AB8(sys); break;
    }
}
