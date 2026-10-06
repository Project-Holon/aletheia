/*
 * function: func_021BB270
 * address: 0x021BB270
 * packet: pkt_ov100_021BB270
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 020399DC at+CC has no outside witness. Scratch one --arm
 *   ARM9-399DC-blocker.log EXACT16: r0 Entry* null=>8; otherwise ldrb+4A.
 *   Full399A8 forwards39338's u16 index to3996C; full3996C returns a 0x50
 *   byte Entry*, passed unchanged in live r0 to399DC. No narrowed address.
 *   typedef unsigned char u8; struct Entry { u8 bytes[0x50]; };
 *   int func_020399DC(struct Entry *p) {
 *     if(p) return p->bytes[0x4a]; return 8;
 *   }
 * blocker: ARM9 veneer0203D170 at+138/+14E = E59FC000 E12FFF1C 0203E590.
 *   Non-C veneer cannot attest unlabelled target; Ilias owns correction.
 *   Reused full verified E590 C from parked ov100BA530, EXACT blocker-1.log;
 *   current show-E590.log proves identical28B body, null guard, byte108.
 *   symbols: d_021469F0 0x021469F0 data a4
 *   extern unsigned char *d_021469F0;
 *   int func_0203E590(void) {
 *     unsigned char *p=d_021469F0;
 *     if(p==0) return 0; return p[0x108];
 *   }
 *   No overlay leaves while either ARM9 blocker remains; no caller retries.
 * diagnosis: caller-only tu --suggest-split MATCH420, 28/31 resolved, zero
 *   viable pieces (021BB270-tu-split.log). dBB804 verdict sole-ref/data;
 *   suggestion mentioning unrelated ov110 data is not ov100 ownership proof.
 * evidence: 399A8 full forwarder calls39338 then3996C, returning Entry*
 *   left in r0; original passes this live result directly to399DC.
 *   Counter increment is unsigned wrapping then signed compare as in ROM.
 * note 2026-10-04 (wD2 lane18): still MATCH, only unresolved relocations remain: func_020399DC filed EXACT as src/matched/arm9/func_020399DC.c (relocation resolves after label regeneration); func_0203D170 veneer (to 0x0203E590, filed EXACT) also needs regeneration.
 * symbols:
 *   func_021BB180 0x021BB180 thumb ov100
 *   func_021BA5F4 0x021BA5F4 thumb ov100
 *   func_021BA3A4 0x021BA3A4 thumb ov100
 *   func_021BA64C 0x021BA64C thumb ov100
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021B97BC 0x021B97BC thumb ov100
 *   func_0203CD98 0x0203CD98 arm
 *   func_020399A8 0x020399A8 arm
 *   func_020399DC 0x020399DC arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BB154 0x021BB154 thumb ov100
 *   func_021BAEE0 0x021BAEE0 thumb ov100
 *   func_021BAF4C 0x021BAF4C thumb ov100
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_0203D170 0x0203D170 arm
 *   func_021BA530 0x021BA530 thumb ov100
 *   func_021BA290 0x021BA290 thumb ov100
 *   d_021BB804 0x021BB804 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Word { int x; };
struct Obj;struct TaskMenu;struct Entry;
extern struct Word d_021BB804[];
extern void func_021BB180(int);
extern void func_021BA5F4(unsigned a);
extern void func_021BA64C(unsigned a, unsigned b);
extern void func_021BA3A4(struct Word *,int);
extern void func_0204B92C(struct Obj *,u32),func_0204B3DC(struct Obj *,u32);
extern void func_021B97BC(int,int,int,int);
extern int func_0203CD98(void);
extern struct Entry *func_020399A8(void);
extern int func_020399DC(struct Entry *);
extern void func_021B95B8(u8 *,u32);
extern void func_021BB154(int p);
extern void func_021BAEE0(int);
extern void func_021BAF4C(int);
extern u32 func_020279E8(struct TaskMenu *);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(struct TaskMenu *),func_02041B6C(u32);
extern int func_0203D170(void);
extern void func_021BA530(int,int),func_021BA290(int,int);
void func_021BB270(int p)
{
    int value;
    if(*(int *)(p+0xc94) && *(int *)(p+0x24c)==5) {
        func_021BB180(p);
    } else if(*(int *)(p+0xc84)==1 && *(int *)(p+0x24c)!=9) {
        if(*(int *)(p+0xc80)==1) {
            func_021BA5F4(p);
            func_021BA3A4(&d_021BB804[*(int *)(p+0x24c)],p);
            func_021BA64C(p,4);
            func_021BA64C(p,5);
            *(int *)(p+0xc80)=0;
            if(*(struct Obj **)(p+0x2c8)) {
                func_0204B92C(*(struct Obj **)(p+0x2c8),0);
                func_0204B92C(*(struct Obj **)(p+0x2d0),0);
            }
        }
        func_021B97BC(p,0,-2,0);
        func_021B97BC(p,0,2,2);
        *(u32 *)(p+0xc88)=*(u32 *)(p+0xc88)+1;
        if(*(int *)(p+0xc88)>30) {
            if(*(struct Obj **)(p+0x2c8)) {
                func_0204B3DC(*(struct Obj **)(p+0x2c8),0);
                func_0204B3DC(*(struct Obj **)(p+0x2d0),0);
            }
            *(int *)(p+0xc84)=0;
        }
    }
    if(func_0203CD98() && func_020399DC(func_020399A8())==7) {
        func_021B95B8((u8 *)p,(u32)func_021BB154);
        return;
    }
    if(func_020279E8(*(struct TaskMenu **)(p+0xcc0))) {
        value=func_02027A04(*(const u8 **)(p+0xcc0));
        func_02027858(*(struct TaskMenu **)(p+0xcc0));
        *(int *)(p+0xcc0)=0;
        func_02041B6C(6);
        if(*(int *)(p+0xcbc)) {
            func_021B95B8((u8 *)p,(u32)func_021BAEE0);return;
        }
        if(value==0) {
            func_021B95B8((u8 *)p,(u32)func_021BAF4C);return;
        } else {
            func_021B95B8((u8 *)p,(u32)func_021BAEE0);return;
        }
    }
    if(*(int *)(p+0x24c)==9) {
        if(*(int *)(p+0xce8)!=func_0203D170()) {
            func_021BA530(0x27,p);
            *(int *)(p+0xce8)=func_0203D170();
        }
        if(*(int *)(p+0xce8)>0 && *(int *)(p+0xcbc)==1) {
            func_02027858(*(struct TaskMenu **)(p+0xcc0));
            *(int *)(p+0xcc0)=0;
            func_021BA290(p,1);
        }
    }
}
