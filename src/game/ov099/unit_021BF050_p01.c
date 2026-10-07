/*
 * file:     unit_021BF050_p01.c
 * unit:     yes
 * function: func_021BF050, func_021BF068, func_021BF084, func_021BF1CC, func_021BF24C, func_021BF280, func_021BF29C, func_021BF2C4, func_021BF6E0, func_021BF950, func_021BFA00, func_021BFA28, func_021BFAD0, func_021BFB04, func_021BFB90, func_021BFBBC
 * address:  0x021BF050
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02156B8C  0x02156B8C  thumb  ov009
 *   func_0203C3EC  0x0203C3EC  arm
 *   func_021BE788 0x021BE788 thumb ov099
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_021B99F4 0x021B99F4 thumb ov099
 *   func_021BE244 0x021BE244 thumb ov099
 *   func_021C203C 0x021C203C thumb ov099
 *   func_021C1A14 0x021C1A14 thumb ov099
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021B9968 0x021B9968 thumb ov099
 *   func_021C2028 0x021C2028 thumb ov099
 *   func_021BE21C 0x021BE21C thumb ov099
 *   func_02082D44 0x02082D44 arm
 *   func_021C207C 0x021C207C thumb ov099
 *   func_020061E4 0x020061E4 thumb
 *   func_021BE7EC  0x021BE7EC  thumb  ov099
 *   func_021BB2B0  0x021BB2B0  thumb  ov099
 *   func_021C2090  0x021C2090  thumb  ov099
 *   func_021B98E4  0x021B98E4  thumb  ov099
 *   func_020221A4 0x020221A4 thumb
 *   func_0203CB00 0x0203CB00 arm
 *   func_0203C9AC 0x0203C9AC arm
 *   func_0203C554 0x0203C554 arm
 *   func_020362DC 0x020362DC arm
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_02005728 0x02005728 thumb
 *   func_0200616C 0x0200616C thumb
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_02156BC4 0x02156BC4 thumb ov009
 *   func_02156BA8 0x02156BA8 thumb ov009
 *   func_02156B70 0x02156B70 thumb ov009
 *   func_021BE900 0x021BE900 thumb ov099
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 *   func_021BAEDC 0x021BAEDC thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021C1BEC 0x021C1BEC thumb ov099
 *   func_021B9B54 0x021B9B54 thumb ov099
 *   func_021B98FC 0x021B98FC thumb ov099
 *   func_021C1968 0x021C1968 thumb ov099
 *   func_021C1A30 0x021C1A30 thumb ov099
 *   func_021C19DC 0x021C19DC thumb ov099
 *   func_021C1B04 0x021C1B04 thumb ov099
 *   func_021B989C 0x021B989C thumb ov099
 *   func_021B98F0 0x021B98F0 thumb ov099
 *   func_021C27F8 0x021C27F8 thumb ov099
 *   func_021C2874 0x021C2874 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BDDA8 0x021BDDA8 thumb ov099
 *   func_021BF03C 0x021BF03C thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021C2864 0x021C2864 thumb ov099
 *   func_021B96D0 0x021B96D0 thumb ov099
 *   func_021B9B64 0x021B9B64 thumb ov099
 *   func_021B9B24 0x021B9B24 thumb ov099
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_02006224 0x02006224 thumb
 *   func_021C23C8 0x021C23C8 thumb ov099
 *   func_021BDE30 0x021BDE30 thumb ov099
 *   func_021BC090 0x021BC090 thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021C282C 0x021C282C thumb ov099
 *   func_021C24A4 0x021C24A4 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02009B80 0x02009B80 thumb
 *   func_02156B68 0x02156B68 thumb ov009
 *   func_021BE3CC 0x021BE3CC thumb ov099
 */
#include "../../matched/include/Obj22049.h"
#include "../../matched/include/Obj22050.h"
#include "../../matched/include/Obj06353.h"
#include "../../matched/include/Obj00901.h"
#include "../../matched/include/Obj03734.h"
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj03223.h"
#include "../../matched/include/Obj22051.h"
#include "../../matched/include/Obj13700.h"

struct Entry;
struct Sub020097BCObj;
struct Link;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BF050;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32_021BF050;

typedef int BOOL;

typedef signed int     s32_021BF084;

typedef unsigned int   u32_021BF084;

typedef unsigned int   u32_021BF1CC;

typedef unsigned long  u32_021BF24C;

typedef signed long    s32_021BF24C;

typedef unsigned long  u32_021BF280;

typedef signed long    s32_021BF280;

typedef unsigned long  u32_021BF29C;

typedef signed long    s32_021BF29C;

typedef unsigned int u32_021BF2C4;

typedef unsigned int u32_021BF6E0;

typedef unsigned int   u32_021BF950;

typedef unsigned int   u32_021BFB04;

typedef unsigned int   u32_021BFBBC;

extern int func_02156B8C(void);
extern int func_0203C3EC(void);
extern int func_021BE788(char *);
extern s32_021BF084 func_0203EFC8(const u8 *a, const u8 *b, unsigned int n);
extern void *func_021BE2A8(char *,int);
extern void func_021B99F4(char *,void *);
extern void func_021BE244(char *,void *);
extern void func_021C203C(char *,int);
extern void func_021C1A14(char *p, int b, void *c);
extern int func_021C23B8(int i);
extern void *func_021B9968(char *,int,int);
extern void func_021C2028(char *p, int i, u8 v);
extern void func_021BE21C(char *,void *);
extern void func_02082D44(void *,void *,int);
extern void func_021C207C(char *);
extern void func_020061E4(u32_021BF084 a);
extern int func_021BE7EC(char *p);
extern void func_021BB2B0(char *p, int v);
extern void func_021C2090(char *p);
extern void func_021B98E4(int a, u8 *b);
extern u32_021BF2C4 func_020221A4(void);
extern int func_0203CB00(void);
extern void func_0203C9AC(int, u32_021BF2C4, u32_021BF2C4, u32_021BF2C4);
extern void func_0203C554(u32_021BF2C4 a);
extern u32_021BF2C4 func_020362DC(void);
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
extern u32_021BF2C4 func_02005728(u32_021BF2C4);
extern void func_0200616C(void *arg, int i);
extern int func_02156A3C(void);
extern void func_02156BC4(int);
extern int func_02156BA8(void);
extern s16 func_02156B70(void);
extern void func_021BE900(char *);
extern void func_021BA874(char *, int);
extern void func_021BAAB8(char *, int, int);
extern void func_021BAADC(char *, int, int);
extern void func_021BAEDC(char *);
extern void func_021C18C8(char *, int, int);
extern void func_021C1BEC(u8 *p);
extern void func_021B9B54(char *);
extern u32_021BF2C4 func_021B98FC(char *);
extern int func_021C1968(char *);
extern void func_021C1A30(u8 *p, int v);
extern void func_021C19DC(char *, int);
extern u8 func_021C1B04(char *, int);
extern void func_021B989C(void *, void *);
extern void func_021B98F0(void *p);
extern int func_021C27F8(char *p, char *q);
extern int func_021C2874(void *);
extern u8 func_021BDD48(char *, void *);
extern u8 func_021BDD54(char *, void *);
extern int func_021BDDA8(int x);
extern int func_021BF03C(char *);
extern int func_021C27E0(void *);
extern void func_021C2864(void *, int);
extern u32_021BF2C4 func_021B96D0(char *);
extern void func_021B9B64(char *);
extern void func_021B9B24(char *);
extern u8 func_021B97F4(char *);
extern int func_021BA928(char *);
extern int func_02006224(u32_021BF950 a0);
extern int func_021C23C8(void *a, void *b);
extern void func_021BDE30(void *p, int kind, int value);
extern void func_021BC090(char *);
extern void func_021C2408(char *);
extern void func_021BA8EC(char *);
extern int func_021C282C(u8 *p);
extern void func_021C24A4(char *, int);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern void func_02009B80(struct Sub020097BCObj *obj, int i);
extern int func_02156B68(char *);
extern void func_021BE3CC(char *p, int a, u8 b, u8 c, u32_021BFBBC d, int e);
BOOL func_021BF050(char *p);
BOOL func_021BF068(char *a0);
int func_021BF084(char *p);
void func_021BF1CC(char *p);
void func_021BF24C(u8 *p, int v);
void func_021BF280(void *a, void *b);
void func_021BF29C(char *p);
int func_021BF2C4(char *p, int ret);
int func_021BF6E0(char *p,int ret);
int func_021BF950(char *p, int ret);
int func_021BFA00(char *p, int ret);
int func_021BFA28(char *p, int ret);
int func_021BFAD0(char *p,int ret);
int func_021BFB04(char *p, int ret);
int func_021BFB90(char *p, int ret);
void func_021BFBBC(char *p);


/*
 * True unless the arm9 predicate answers -1.
 *
 * Unblocked by matching func_02156B8C (ov009, EXACT): the +0002 call site now
 * attests as `matched`.  The old `ov172` hint was simply wrong -- 0x02156B8C
 * is not inside ov172's window; the address is coherent Thumb code in ov009
 * (ov010 holds the tail of another function there).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021BF050.c --func func_021BF050 --addr 0x021BF050 \n    --region ov099 --thumb --cc dsi/1.1p1
 */
BOOL func_021BF050(char *p)
{
    if (func_02156B8C() != -1) {
        return 1;
    }

    return 0;
}


/*
 * Channel-id predicate: true when func_0203C3EC() answers 3, 4 or 5.
 * `push {r3, lr}; blx; cmp r0, #3; beq; cmp r0, #4; beq; cmp r0, #5; bne;
 * movs r0, #1; pop; movs r0, #0; pop`.
 *
 * Now EXACT*.  The old blocker (0x0203C3EC had no witness) is gone: it was
 * matched in arm9 (src/matched/func_0203C3EC.c, shard pkt_0203C3EC), so
 * `attest_matched` resolves the BLX field.  The remaining residue was codegen:
 * the old `v == 3 || v == 4 || v == 5` source folded to a range test, and a
 * chain of separate `if`s oriented the true arm last.  A bare `switch (v)`
 * with fallthrough case labels 3/4/5 lays the true arm out first, exactly as
 * the original does; the 26 bytes all agree.  The inferred extent ran to 28
 * because the next function (0x021BF082) has no func_ label.
 */
BOOL func_021BF068(char *a0)
{
    int v = func_0203C3EC();

    switch (v) {
    case 3:
    case 4:
    case 5:
        return 1;
    }
    return 0;
}

/*
 * lever: duplicated calls in the final if/else-if preserve the branch-to-branch tail.
 */
int func_021BF084(char *p)
{
    int ret=func_021BE788(p);
    int removed=0;
    int added=0;
    int i,j,found;
    void *v;
    char *s;
    if(func_0203EFC8((const u8 *)(p+0x10),(const u8 *)(p+0x30),32)){
        for(i=0;i<32;i++){
            found=0;
            for(j=0;j<32;j++){
                if(*(u8 *)(p+j+0x10)==*(u8 *)(p+i+0x30)){found=1;break;}
            }
            if(!found && *(u8 *)(p+i+0x30)){
                v=func_021BE2A8(p,*(u8 *)(p+i+0x30));
                if(v){
                    func_021B99F4(p+0x274,v);
                    func_021BE244(p,v);
                    func_021C203C(p,*(u8 *)(p+i+0x30));
                    func_021C1A14(p,*(u8 *)(p+i+0x30),(void *)33);
                    added=1;
                }else{
                    func_021C203C(p,*(u8 *)(p+i+0x30));
                }
            }
            found=0;
            for(j=0;j<32;j++){
                if(*(u8 *)(p+i+0x10)==*(u8 *)(p+j+0x30)){found=1;break;}
            }
            if(!found && *(u8 *)(p+i+0x10)){
                s=(char *)func_021C23B8(*(u8 *)(p+i+0x10)-1);
                v=func_021B9968(p+0x274,((struct Obj22049 *)s)->f14,*(u8 *)(p+i+0x10));
                if(v){
                    func_021C2028(p,*(u8 *)(p+i+0x10),2);
                    func_021BE21C(p,v);
                    removed=1;
                }else{
                    func_021C2028(p,*(u8 *)(p+i+0x10),1);
                }
            }
        }
        func_02082D44(p+0x10,p+0x30,32);
        if(removed || added)func_021C207C(p);
        if(removed==1){func_020061E4(0x676);}
        else if(added==1){func_020061E4(0x676);}
    }
    return ret;
}

void func_021BF1CC(char *p)
{
    int changed = 0;
    int i;
    void *v;
    char *s;
    for (i = 0; i < 32; i++) {
        if (*(u8 *)(p + i + 0x10) && !func_021BE2A8(p, *(u8 *)(p + i + 0x10))) {
            s = (char *)func_021C23B8(*(u8 *)(p + i + 0x10) - 1);
            v = func_021B9968(p + 0x274, ((struct Obj22050 *)s)->f14, *(u8 *)(p + i + 0x10));
            if (v) {
                func_021C2028(p, *(u8 *)(p + i + 0x10), 2);
                func_021BE21C(p, v);
                *(u8 *)(p + i + 0x50) = 0;
                *(u8 *)(p + i + 0x70) = 0;
                *(u8 *)(p + i + 0x90) = 0;
                changed = 1;
            }
        }
    }
    if (changed == 1) func_020061E4(0x676);
}


/*
 * Under a positive answer from func_021BE7EC, routes on the flag at +0x8EF:
 * hands the selector to func_021BB2B0 when set, otherwise raises the word at
 * +0x8F4 and calls func_021C2090.
 */
void func_021BF24C(u8 *p, int v)
{
    if (func_021BE7EC((char *)p) <= 0) {
        return;
    }

    if (p[0x8EF] != 0) {
        func_021BB2B0((char *)p, v);
        return;
    }

    ((struct Obj06353 *)p)->f8F4 = 1;
    func_021C2090((char *)p);
}


void func_021BF280(void *a, void *b)
{
    func_021BF084(a);
    func_021BF24C(a, (int)b);
    func_021BF1CC(a);
}


/*
 * Releases the block 0x274 bytes in once for every occupied slot of the
 * 0x21-entry pointer table at +0x814.  The slot value is the SECOND argument of
 * func_021B98E4, which is why the image loads it into r1 and keeps it live into
 * the call; that liveness, not an allocator quirk, is the byte the lane before
 * this one measured as a residue.
 */
void func_021BF29C(char *p)
{
    int i;

    for (i = 0; i < 0x21; i++) {
        void *v = *(void **)(p + i * 4 + 0x814);

        if (v != 0) {
            func_021B98E4((int)(p + 0x274), v);
        }
    }
}

/*
 *   ov099_func_021BFB04.c, itself copied from ov099_func_021BEB68.c
 *   (leaf-cb00-r1.log).
 *   extern char *d_021469DC;
 *   extern void func_0203CADC(void);
 *   int func_0203CB00(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)func_0203CADC) return 1;
 *       }
 *       return 0;
 *   }
 * shape: the nested record test preserves its branch-to-branch;
 *   the named call-result value fixes cmp r0,r1 at +0176.
 * prototype: 021C1968 tail forwards the result read by this caller;
 *   0203D7B0/0203D7BC keep the visible r0 argument; 021C2864's
 *   r1 stays full-width because neither call site truncates it.
 */
int func_021BF2C4(char *p, int ret)
{
    u32_021BF2C4 action = 0, kind;
    int index, i, key, value;
    void *record;
    *(u8 *)(p + 0x1356) = 0;
    if (func_020221A4() == 0) return ret;
    if (func_0203CB00()) { func_021BE900(p); return ret; }
    if (*(int *)(p + 0x1f0) != -1) {
        if (++*(int *)(p + 0x1c8) > 0xe10) { func_0203C9AC(0, 0, 0, 0x3f1); return ret; }
    }
    if (func_0203C3EC() == 4) {
        func_021BA874(p, func_02156A3C());
        func_021BAAB8(p, 15, 0);
        *(int *)(p + 0x1cc) = 21;
        func_021C18C8(p, 1, 2);
        func_0203C554(1);
        return ret;
    }
    func_021BF280(p, (void *)33);
    func_021C1BEC((u8 *)p);
    func_021B9B54(p + 0x274);
    if (func_021B98FC(p + 0x274) == 0) {
        if (func_02156B8C() == -1 && (func_020362DC() & 0x400)) {
            if (func_021C1968(p)) func_021BAADC(p, 57, 0);
            else func_021BAADC(p, 58, 0);
            func_020061E4(0x54c);
            func_021BAEDC(p);
            *(int *)(p + 0x1cc) = 12;
            func_021C1A30((u8 *)p, 33);
            return ret;
        }
        key = func_021C1B04(p, 33);
        record = func_021BE2A8(p, key);
        if (key != 0) {
            if (record != 0) func_021B989C(p + 0x274, record);
            else { func_021BF29C(p); func_021B98F0(p + 0x274); }
        } else { func_021BF29C(p); func_021B98F0(p + 0x274); }
    }
    for (i = 0; i < 32; i++) {
        index = func_02005728(32);
        if (func_021C27F8(*(void **)(p + 8), (char *)func_021C23B8(index)) != 0) {
            value = func_021C2874((void *)func_021C23B8(index));
            if (value != *(*(u8 **)(p + 0x248) + index + 0x24)) {
            func_021BDD48(p, (void *)func_021C23B8(index));
            func_021BDD54(p, (void *)func_021C23B8(index));
            *(u16 *)(p + 0x242) = index + 1;
            func_0200616C((void *)0x806, 0);
            *(int *)(p + 0x1cc) = 63;
            return ret;
            }
        }
    }
    if (func_021BF03C(p) && *(int *)(p + 0x1f0) != -1) {
        func_0200616C((void *)0x806, 0);
        func_0203D7B0(1);
        func_0203D7BC(1);
        *(int *)(p + 0x1cc) = 40;
        return ret;
    }
    if (*(int *)(p + 0x1f0) == -1 && func_02156B8C() != -1) {
        index = func_02156B8C();
        *(int *)(p + 0x1f0) = index;
        func_021BA874(p, index);
        if (!*(u8 *)(p + 0x1351)) func_021BAAB8(p, 46, 0);
        *(int *)(p + 0x1c8) = 0;
    } else if (*(int *)(p + 0x1f0) != -1 && func_02156B8C() == -1) {
        func_02156BC4(0);
        func_021C2864(*(void **)(p + 8), func_021C27E0(*(void **)(p + 8)));
        func_021BA874(p, *(int *)(p + 0x1f0));
        func_021BAAB8(p, 15, 0);
        func_0203C554(1);
        *(int *)(p + 0x1cc) = 19;
        return ret;
    }
    if (func_021BF068(p) && *(int *)(p + 0x1f0) != -1) {
        func_021BA874(p, func_02156BA8());
        func_021BAAB8(p, 15, 0);
        *(int *)(p + 0x1cc) = 19;
        return ret;
    }
    if (func_02156B70() == 1 && func_02156B8C() == -1) {
        func_02156BC4(0);
        func_021C2864(*(void **)(p + 8), func_021C27E0(*(void **)(p + 8)));
    }
    kind = func_021BDD48(p, *(void **)(p + 8));
    if (*(int *)(p + 0x1f0) == -1) {
        if ((func_020362DC() & 2) && func_021BDDA8(kind)) {
            func_020061E4(0x54c);
            *(int *)(p + 0x1cc) = 31;
            func_021C19DC(p, 33);
            return ret;
        }
        action = func_021B96D0(p + 0x274);
        func_021B9B64(p + 0x274);
    }
    switch (action) {
    case 0: return ret;
    case 1:
        func_020061E4(0x54c);
        if (func_021BDDA8(kind)) *(int *)(p + 0x1cc) = 31;
        else {
            *(int *)(p + 0x1d0) = 0;
            *(int *)(p + 0x1cc) = 49;
            func_021BAAB8(p, 25, 1);
        }
        func_021C1A30((u8 *)p, 33);
        return ret;
    case 3:
        if (kind == 1) {
            *(int *)(p + 0x135c) = 1;
            func_020061E4(0x54c);
            func_021B9B24(p + 0x274);
            *(int *)(p + 0x1cc) = 28;
            func_021C1A30((u8 *)p, 33);
            *(u8 *)(p + 0x1351) = 0;
            return ret;
        }
        break;
    case 2:
        if (kind == 1) {
            index = func_021B97F4(p + 0x274);
            func_020061E4(0x54c);
            func_02082D44((void *)func_021C23B8(index - 1), p + 0x24c, 32);
            *(int *)(p + 0x1cc) = 34;
            func_021C1A30((u8 *)p, 33);
            return ret;
        }
        break;
    }
    return ret;
}

int func_021BF6E0(char *p,int ret)
{
    unsigned action=0,kind;
    int index;
    if(((struct Obj00901 *)p)->f1F0!=-1){
        if(++((struct Obj00901 *)p)->f1C8>0xe10){func_0203C9AC(0,0,0,0x3f1);return ret;}
    }
    func_021BA928(p);
    ((struct Obj00901 *)p)->f1356=0;
    func_021BF280(p,(void *)33);
    func_021C1BEC((u8 *)p);
    func_021B9B54(p+0x274);
    if(func_021BF03C(p) && ((struct Obj00901 *)p)->f1F0!=-1){
        func_0200616C((void *)0x806,0);
        func_0203D7B0(1);
        func_0203D7BC(1);
        ((struct Obj00901 *)p)->f1CC=40;
        return ret;
    }
    if(func_021BF068(p) && ((struct Obj00901 *)p)->f1F0!=-1){
        func_021BA874(p,func_02156BA8());
        func_021BAAB8(p,15,0);
        ((struct Obj00901 *)p)->f1CC=19;
        return ret;
    }
    if(((struct Obj00901 *)p)->f1F0==-1 && func_02156B8C()!=-1){
        index=func_02156B8C();
        ((struct Obj00901 *)p)->f1F0=index;
        func_021BA874(p,index);
        if(!((struct Obj00901 *)p)->f1351)func_021BAAB8(p,46,0);
        ((struct Obj00901 *)p)->f1C8=0;
    }else if(func_02156BA8()!=-1){
        func_021BA874(p,func_02156BA8());
        func_021BAAB8(p,15,0);
        ((struct Obj00901 *)p)->f1CC=19;
        return ret;
    }
    kind=func_021BDD48(p,((struct Obj00901 *)p)->f8);
    if(((struct Obj00901 *)p)->f1F0==-1){
        if((func_020362DC()&2) && func_021BDDA8(kind)){
            func_020061E4(0x54c);
            ((struct Obj00901 *)p)->f1CC=31;
            func_021C1A30((u8 *)p,33);
            return ret;
        }
        action=func_021B96D0(p+0x274);
        func_021B9B64(p+0x274);
    }
    switch(action){
    case 0:return ret;
    case 1:
        func_020061E4(0x54c);
        if(func_021BDDA8(kind)){
            ((struct Obj00901 *)p)->f1CC=31;
        }else{
            ((struct Obj00901 *)p)->f1D0=0;
            ((struct Obj00901 *)p)->f1CC=49;
            func_021BAAB8(p,25,1);
        }
        func_021C1A30((u8 *)p,33);
        return ret;
    case 3:
        if(kind==1){
            ((struct Obj00901 *)p)->f135C=1;
            func_020061E4(0x54c);
            func_021B9B24(p+0x274);
            ((struct Obj00901 *)p)->f1CC=28;
            func_021C1A30((u8 *)p,33);
            return ret;
        }
        break;
    case 2:
        if(kind==1){
            index=func_021B97F4(p+0x274);
            func_020061E4(0x54c);
            func_02082D44((void *)func_021C23B8(index-1),p+0x24c,32);
            ((struct Obj00901 *)p)->f1CC=34;
            func_021C1A30((u8 *)p,33);
            return ret;
        }
        break;
    }
    return ret;
}

/*
 * lever: pointer addition spells base + index + 0x24, avoiding indexed strb.
 */
int func_021BF950(char *p, int ret)
{
    int i = ((struct Obj03734 *)p)->f242 - 1;
    if (func_02006224(0)) return ret;
    *(*(u8 * *)&((struct Obj03734 *)p)->f248 + i + 0x24) = func_021C2874((void *)func_021C23B8(i));
    if (i >= 0 && i < 32 && func_021C23C8(p, (void *)i)) {
        ((struct Obj03734 *)p)->f1C4 = 0xe10;
        func_021BDE30(p, 4, 3);
        func_021C18C8(p, 4, 3);
        func_021C19DC(p, 0x21);
        func_021BA874(p, i);
        ((struct Obj03734 *)p)->f1C4 = 0xe10;
        func_021BAADC(p, 0x5e, 0);
        func_021BC090(p);
        ((struct Obj03734 *)p)->f1CC = 0x25;
        ((struct Obj03734 *)p)->f1350 = ((struct Obj03734 *)p)->f242;
        return ret;
    }
    ((struct Obj03734 *)p)->f1CC = 0xb;
    return ret;
}

int func_021BFA00(char *p, int ret) {
 if (func_020362DC()) { ((struct Obj00008 *)p)->f1CC=11; func_021C2408(p); func_021BA8EC(p); }
 return ret;
}

int func_021BFA28(char *p, int ret)
{
    void *s;
    unsigned v;
    s = (void *)func_021C23B8(((struct Obj03223 *)p)->f242 - 1);
    func_021C27E0(s);
    v = func_021BDD48(p, s);
    ((struct Obj03223 *)p)->f1C4 -= 1;
    if (((struct Obj03223 *)p)->f1C4 < 0) {
        ((struct Obj03223 *)p)->f1CC = 0x3d;
    } else if (v != 1 && v != 2) {
        func_021BA874(p, func_02156A3C());
        func_021BAAB8(p, 0xd, 0);
        ((struct Obj03223 *)p)->f1CC = 0x13;
    } else if (func_0203C3EC() == 1) {
        func_021BA8EC(p);
        func_021C282C(((struct Obj03223 *)p)->f8);
        ((struct Obj03223 *)p)->f1351 = 0;
        func_021C18C8(p, 4, 4);
        ((struct Obj03223 *)p)->f1355 = 0;
        ((struct Obj03223 *)p)->f1CC = 0x10;
        func_021C24A4(p, 0);
        func_021BAADC(p, 0x7b, 0);
    }
    return ret;
}

/*
 * Extent ends with two-byte alignment padding at 0x021BFB02.
 */
int func_021BFAD0(char *p,int ret) {
 func_021BA874(p,func_02156A3C());
 func_021BAAB8(p,11,0);
 func_021C18C8(p,4,4);
 ((struct Obj22051 *)p)->f1CC=15;
 return ret;
}

int func_021BFB04(char *p, int ret)
{
    if (func_0203CB00()) {
        func_021BE900(p);
        return ret;
    }
    if (func_02156A3C() < 0) {
        func_021BAAB8(p, 0x10, 0);
        *(int *)(p + 0x1cc) = 0x13;
        return ret;
    }
    if (func_021BA928(p)) {
        if (func_020362DC() & 3) {
            func_021BA8EC(p);
            func_021BAADC(p, 0x7b, 0);
            func_021C18C8(p, 4, 4);
            func_021C24A4(p, 0);
            *(u8 *)(p + 0x1355) = 0;
            *(int *)(p + 0x1cc) = 0x10;
        } else {
            func_021BFB90(p, ret);
        }
    }
    return ret;
}

int func_021BFB90(char *p, int ret) {
 func_02039C68((struct Link *)func_020399A8(),19,10);
 func_02009B80(((struct Obj13700 *)p)->f4,func_02156A3C());
 ((struct Obj13700 *)p)->f1CC=149;
 return ret;
}

void func_021BFBBC(char *p)
{
    if (func_02156B68(p)) {
        func_021BE3CC(p + 0x898, 1, 2, 1, 0x3c, 0);
    } else {
        func_021BE3CC(p + 0x898, 1, 2, 1, 0x33, 0);
    }
}
