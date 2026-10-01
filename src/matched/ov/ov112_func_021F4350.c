/*
 * function: func_021F4350
 * address: 0x021F4350
 * packet: pkt_ov112_021F4350
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: byte +8 is re-read after the increment at 0x021F44BA.
 * ABI: 0200A640 leaves its incoming pointer in r0; the caller copies that return.
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_021F4794 0x021F4794 thumb ov112
 *   func_021F485C 0x021F485C thumb ov112
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   func_0200A640 0x0200A640 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 *   func_021F4804 0x021F4804 thumb ov112
 *   func_0200FB24 0x0200FB24 thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_02045334 0x02045334 arm
 *   func_020310C4 0x020310C4 arm
 *   func_02041EE4 0x02041EE4 arm
 *   d_021F8290 0x021F8290 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 b[8]; } Box;
extern const Box d_021F8290;
extern void func_020061E4(u32);
extern u32 func_020221A4(void);
extern void func_021F4794(u8 *,u32);
extern void func_021F485C(u8 *);
extern void func_02027974(void *);
extern u32 func_020279E8(void *);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(void *);
extern void *func_0200A640(void *);
extern void func_02082D44(const void *,void *,u32);
extern void func_021FCDEC(int,int);
extern int func_021FCE00(void *,int);
extern void func_021F4804(u8 *,u32);
extern u32 func_0200FB24(void);
extern void *func_020362DC(void);
extern int func_02035C08(const Box *);
extern void func_0204B878(void *,u16);
extern void func_0204B92C(void *,u32);
extern u32 func_0204B98C(void *);
extern u32 func_0201CE30(void *);
extern void func_0201CE48(void *);
extern u32 func_0201C4E4(void *);
extern u32 func_0201C6B4(const void *);
extern u8 *func_0202EE8C(u32,void *,u8,u8,u16);
extern void func_02045334(void *);
extern void func_020310C4(void *);
extern void func_02041EE4(u32,u32,u32);
void func_021F4350(u8 *p)
{
    u8 v;
    switch (*(u32 *)(p+4)) {
    case 0:
        *(u32 *)(p+4)=1;
        func_020061E4(1583);
    case 1:
        if(func_020221A4()==1) {
            if(*(u32 *)(p+12)==1) {
                func_021F4794(p,3);
                *(u32 *)(p+4)=2;
            } else *(u32 *)(p+4)=5;
        }
        break;
    case 2:
        if(!*(void **)(p+36)) {
            func_021F485C(p);
            *(u32 *)(p+4)=3;
        }
        break;
    case 3:
        func_02027974(*(void **)(p+60));
        if(func_020279E8(*(void **)(p+60))==1) {
            v=func_02027A04(*(u8 **)(p+60));
            func_02027858(*(void **)(p+60));
            if(v==0) func_02082D44(*(void **)(p+16),func_0200A640(*(void **)(p+20)),432);
            if(*(int *)(p+68)) {
                *(u32 *)(p+4)=4;
                func_021FCDEC(*(int *)(p+68),71);
                func_021F4804(p,6);
            } else *(u32 *)(p+4)=7;
        } else if(func_0200FB24()!=0) {
            func_02027858(*(void **)(p+60));
            *(u32 *)(p+4)=7;
        }
        break;
    case 4:
        if(func_021FCE00(*(void **)(p+68),71)==1) *(u32 *)(p+4)=7;
        else if(func_0200FB24()!=0) *(u32 *)(p+4)=7;
        break;
    case 5:
        if(((u32)func_020362DC()&2)||!func_02035C08(&d_021F8290)) {
            func_020061E4(1361);
            *(u32 *)(p+4)=6;
            func_0204B878(*(void **)(p+88),9);
            func_0204B92C(*(void **)(p+88),1);
        }
        break;
    case 6:
        if(!func_0204B98C(*(void **)(p+88))) *(u32 *)(p+4)=7;
        break;
    case 7: break;
    }
    if(*(void **)(p+36)&&func_0201CE30(*(void **)(p+36))==2) {
        func_0201CE48(*(void **)(p+36));
        *(void **)(p+36)=0;
    }
    func_0201C4E4(*(void **)(p+56));
    if(*(u32 *)(p+48)==1&&func_0201C6B4(*(void **)(p+56))==1) {
        *(u32 *)(p+48)=0;
        *(u8 **)(p+52)=func_0202EE8C(*(u32 *)(p+24),*(void **)(p+28),15,16,*(u16 *)p);
        func_02045334(*(void **)(p+28));
    }
    func_020310C4(*(void **)(p+24));
    (*(volatile u8 *)(p+8))++;
    if(*(volatile u8 *)(p+8)>1) {
        *(volatile u8 *)(p+8)=0;
        func_02041EE4(7,1,1);
        func_02041EE4(7,5,1);
    }
}
