/*
 * file:     wifibattlematch_net_p01.c
 * unit:     yes
 * function: func_021D4240, func_021D429C, func_021D42E0, func_021D4318, func_021D4448, func_021D44D4
 * address:  0x021D4240
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
 *   ov177_id 0x000000B1 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034714 0x02034714 arm
 *   d_021E2C74 0x021E2C74 data a4
 *   d_021E2C80 0x021E2C80 data a4
 *   d_021E2DE0 0x021E2DE0 data
 *   func_02006210 0x02006210 thumb
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 *   ov114_id 0x00000072 data
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021E5440 0x021E5440 thumb ov177
 *   func_021E5548 0x021E5548 thumb ov177
 *   func_021E567C 0x021E567C thumb ov177
 *   func_021D6698 0x021D6698 thumb ov175
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC74 0x0201EC74 thumb
 *   func_021D9DC8 0x021D9DC8 thumb ov175
 *   func_021E8568 0x021E8568 thumb ov177
 *   func_021E8A3C 0x021E8A3C thumb ov177
 *   func_021D458C 0x021D458C thumb ov175
 *   func_021E7D20 0x021E7D20 thumb ov177
 *   func_021E7E0C 0x021E7E0C thumb ov177
 *   func_021D6524 0x021D6524 thumb ov175
 *   func_021D63C8 0x021D63C8 thumb ov175
 *   func_021DD008 0x021DD008 thumb ov175
 *   func_021E7DF0 0x021E7DF0 thumb ov177
 *   func_021E8A78 0x021E8A78 thumb ov177
 *   func_021E8628 0x021E8628 thumb ov177
 *   func_021D9EA0 0x021D9EA0 thumb ov175
 *   func_021D644C 0x021D644C thumb ov175
 *   func_021D639C 0x021D639C thumb ov175
 *   func_021D65C8 0x021D65C8 thumb ov175
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021E5868 0x021E5868 thumb ov177
 *   func_021E54E0 0x021E54E0 thumb ov177
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021E8A80 0x021E8A80 thumb ov177
 *   func_021E8A90 0x021E8A90 thumb ov177
 *   func_021D9ED0 0x021D9ED0 thumb ov175
 *   func_021E5534 0x021E5534 thumb ov177
 *   func_021E867C 0x021E867C thumb ov177
 *   func_021E7E08 0x021E7E08 thumb ov177
 *   func_021E5980 0x021E5980 thumb ov177
 *   func_021E64C0 0x021E64C0 thumb ov177
 *   func_021E7774 0x021E7774 thumb ov177
 */
struct Obj0203159C;
struct GfFont;
struct MsgBank;
struct WordSet;
struct PrintSys;
struct Rec;
struct S020315D4;
typedef int (*Callback)(int,int,int *,int);

typedef struct { Callback create,other,close; } Table;

typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern int func_02034AC4(s32 handle);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02034A5C(int);
extern void func_02006210(void);
extern void func_0203064C(u32, u32, u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *, int, u32);
extern int *func_021E5440(unsigned, int);
extern int func_021E5548(int *);
extern u32 *func_021E567C(int unused, int mode, int heap);
extern void func_021D6698(u32 *, u32 *);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC74(u32 n, u32 size, unsigned short heap);
extern char *func_021D9DC8(u32 a, void *save, u32 b, u16 heap);
extern void *func_021E8568(unsigned, unsigned, unsigned, unsigned, void *, void *, unsigned);
extern int *func_021E8A3C(int, int, int);
extern void func_021D458C(unsigned sys, int *state, int *p);
extern void **func_021E7D20(void *, void *, unsigned);
extern void func_021E7E0C(void **, int);
extern void func_021D6524(int, int, u32);
extern void func_021D63C8(char *, u32);
extern void func_021DD008(char *, int);
extern void func_021E7DF0(int *p);
extern void func_021E8A78(void *p);
extern void func_021E8628(char *p);
extern void func_021D9EA0(u8 *p);
extern void func_021D644C(char *);
extern void func_021D639C(char *);
extern void func_021D65C8(char *);
extern unsigned int func_0201ED04(struct WordSet *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_021E5868(int);
extern void func_021E54E0(char *p);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021E8A80(unsigned);
extern int func_021E8A90(int **p);
extern void func_021D9ED0(int);
extern void func_021E5534(u8 *p);
extern void func_021E867C(char *p);
extern void func_021E7E08(int);
extern void func_021E5980(int);
extern int func_021E64C0(unsigned char *,void *);
extern int func_021E7774(void *p, void *mgr);
int func_021D4240(int a,int b,int *p,int d);
int func_021D429C(int a,int b,int *p,int d);
int func_021D42E0(int a,int b,int *p,int d);
int func_021D4318(void *sys, int *state, u32 *ctx);
int func_021D4448(int sys,int unused,int unused2,int *p);
int func_021D44D4(unsigned sys,int *state,int unused,int *p);
extern const Table d_021E2C74,d_021E2C80;
extern const char d_021E2DE0[];
extern const char ov177_id[];
extern const char ov067_id[], ov114_id[];
extern const char ov114_id[],ov067_id[];

int func_021D4240(int a,int b,int *p,int d)
{
    func_02034AC4((int)ov177_id);
    switch(((int *)p[2])[2]) {
    case 1: return d_021E2C74.create(a,b,p,d);
    case 0: return d_021E2C80.create(a,b,p,d);
    default: func_02034714(d_021E2DE0,0,d_021E2DE0); return 0;
    }
}

int func_021D429C(int a,int b,int *p,int d)
{
    int result;
    switch(((int *)p[2])[2]) {
    case 1: result=d_021E2C74.close(a,b,p,d); break;
    case 0: result=d_021E2C80.close(a,b,p,d); break;
    default: func_02034714(d_021E2DE0,0,d_021E2DE0); break;
    }
    func_02006210();
    func_02034A5C((int)ov177_id);
    return result;
}

int func_021D42E0(int a,int b,int *p,int d) {switch(((int *)p[2])[2]) {case 1:return d_021E2C74.other(a,b,p,d);case 0:return d_021E2C80.other(a,b,p,d);default:func_02034714(d_021E2DE0,0,d_021E2DE0);return 0;}}

/*
 * prototype: 0203159C's matched void body leaves allocated r0 live;
 *   caller captures r0 at 021D4348 as its cleared 0x100-byte buffer.
 */
int func_021D4318(void *sys, int *state, u32 *ctx)
{
    u32 *p;
    func_02034AC4((int)ov067_id);
    func_02034AC4((int)ov114_id);
    func_0203064C(1, 87, 0x35000);
    p = func_0203159C(sys, 0x100, 87);
    func_02082BCC(p, 0, 0x100);
    p[16] = (u32)ctx;
    p[0] = (u32)func_021E5440(1, 87);
    p[1] = (u32)func_021E567C(func_021E5548((int *)p[0]), 2, 87);
    func_021D6698((u32 *)ctx[5], p);
    p[2] = (u32)func_0201D7EC(23, 0, 0, 0, 87);
    p[3] = func_0201C440((void *)87);
    p[4] = (u32)func_02045B38(0, 2, 210, 87);
    p[5] = (u32)func_0201EC74(8, 64, 87);
    p[12] = (u32)func_021D9DC8(((u32 *)p[16])[15], (void *)(((u32 *)ctx[2])[0]), ctx[7], 87);
    p[9] = (u32)func_021E8568(0, 15, 14, 10, (void *)p[3], (void *)p[2], 87);
    p[13] = (u32)func_021E8A3C((int)p, (int)func_021D458C, 87);
    p[14] = (u32)func_021E8A3C((int)p, 0, 87);
    p[8] = (u32)func_021E7D20((void *)func_021E5548((int *)p[0]), (void *)p[1], 87);
    func_021E7E0C((void **)p[8], 0);
    if (ctx[3] != 0) {
        if (ctx[0] == 0) {
            func_021D63C8((char *)p, 0);
        } else if (ctx[0] == 1) {
            if (ctx[3] == 1)
                func_021D6524(ctx[4], ((u32 *)ctx[2])[1], *(u32 *)ctx[11]);
            func_021D63C8((char *)p, 1);
        }
    }
    func_021DD008((char *)p[12], 1);
    return 1;
}

int func_021D4448(int sys,int unused,int unused2,int *p)
{
    func_021DD008((char *)p[12],0);
    func_021E7DF0((int *)p[8]);
    func_021E8A78((void *)p[14]);
    func_021E8A78((void *)p[13]);
    func_021E8628((char *)p[9]);
    if(p[12]) func_021D9EA0((u8 *)p[12]);
    func_021D644C((char *)p);
    func_021D639C((char *)p);
    func_021D65C8((char *)p);
    func_0201ED04((struct WordSet *)p[5]);
    func_02045C04((void *)p[4]);
    func_0201C4C0((struct PrintSys *)p[3]);
    func_0201D83C((void *)p[2]);
    func_021E5868(p[1]);
    func_021E54E0((char *)p[0]);
    func_020315D4((struct S020315D4 *)sys);
    func_020306F0(0x57);
    func_02034A5C((int)ov114_id);
    func_02034A5C((int)ov067_id);
    return 1;
}

/*
 * Extent tail 021D458A..021D458C is two zero alignment bytes before 021D458C.
 */
int func_021D44D4(unsigned sys,int *state,int unused,int *p)
{
    switch(*state) {
    case 0: func_0204E720(3,16,0,0); *state=1; break;
    case 1: if(func_0204E804()==0) *state=2; break;
    case 2:
        func_021E8A80(p[13]);
        if(func_021E8A90((int **)p[13])) *state=3;
        if(p[12]) func_021D9ED0(p[12]);
        break;
    case 3: func_0204E720(3,0,16,0); *state=4; break;
    case 4: if(func_0204E804()==0) return 1; break;
    }
    func_021E5534((u8 *)p[0]);
    func_0201C4E4((struct PrintSys *)p[3]);
    func_021E867C((char *)p[9]);
    func_021E7E08(p[8]);
    func_021E5980(p[1]);
    if(p[6]) func_021E64C0((unsigned char *)p[6],(void *)p[3]);
    if(p[7]) func_021E7774((void *)p[7],(void *)p[3]);
    return 0;
}
