/*
 * function: func_021DABCC
 * address: 0x021DABCC
 * packet: pkt_ov131_021DABCC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: initialized bounded descriptor list and explicit controller arms;
 *   unsigned distance wrap preserves the original signed tests at INT_MIN.
 * output: BA14 writes all four bytes for each index0..4; terminal record
 *   first byte255 stops ADC before any remaining terminal bytes are read.
 *   Both C08->BBC and BA4->B58 return -1 or0..4 for this list; predicates
 *   do not write it. BA54 writes both halfwords before their consumers.
 * arithmetic: admitted index0..4 after -1 rejection keeps index+54 and
 *   index*24 representable; byte record selectors retain0..255, *24<=6120.
 *   Full word distance uses u32 subtraction/negation modulo2^32, with
 *   original signed tests; INT_MIN retains its wrapped negative result.
 * interfaces: observed C38/C60 scalar returns retained despite legacy
 *   own void wrappers; every original call argument and independent poll
 *   remains. No owner C, defaults, extra bound, volatile or signed overflow.
 * symbols:
 *   func_021D5A9C 0x021D5A9C thumb ov131
 *   func_021DBA78 0x021DBA78 thumb ov131
 *   func_021D9E30 0x021D9E30 thumb ov131
 *   func_021DBA14 0x021DBA14 thumb ov131
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021DBA54 0x021DBA54 thumb ov131
 *   func_021DB468 0x021DB468 thumb ov131
 *   func_021DB508 0x021DB508 thumb ov131
 *   func_02035C60 0x02035C60 arm
 *   func_02035C38 0x02035C38 arm
 *   func_02035C08 0x02035C08 arm
 *   func_02035BA4 0x02035BA4 arm
 *   func_02017E88 0x02017E88 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B9A0 0x0204B9A0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
struct Actor;
struct Vec2 { s16 x,y; };
extern void func_021D5A9C(char *,int);
extern void func_021DBA78(u8 *,int);
extern void func_021D9E30(void *a, int b);
extern void func_021DBA14(u8 *,u8 *);
extern void *func_021D6064(u8 *);
extern void func_021DBA54(u8 *,u8 *);
extern void func_021DB468(u8 *,u8 *,u8,int);
extern void func_021DB508(u8 *,u8 *,u32,u32);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern int func_02035C08(u8 *);
extern int func_02035BA4(u8 *);
extern u32 func_02017E88(void *,u32,u32);
extern void func_020061E4(u32);
extern void func_0204B878(struct Obj *,u16);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32);
extern void func_0204B9A0(struct Actor *);
void func_021DABCC(u8 *a,u8 *b)
{
    u8 i;
    int index;
    u32 distance;
    u8 touch[6][4];
    struct Vec2 point2;
    struct Vec2 point1;
    if (*(int *)(a+36)==7 && *(int *)(a+68)==0) {
        func_021D5A9C((char *)a,1);
        func_0204B878(*(struct Obj **)(a+404),9);
        func_021DBA78(b+176+b[41]*24,0);
        func_0204B3DC(*(struct Obj **)(b+152),0);
        func_021D9E30(a,(int)b);
        if (*(int *)(b+20)==1) {
            func_021DBA78(b+176+b[42]*24,0);
            func_0204B3DC(*(struct Obj **)(b+156),0);
            *(int *)(b+20)=0;
            b[42]=5;
        }
        a[28]=1;
        func_020061E4(1361);
        return;
    }
    for (i=0;i<5;i++) func_021DBA14(b+176+i*24,touch[i]);
    touch[5][0]=255;
    if (func_02035C60()==1) {
        index=func_02035C08(touch[0]);
        if (index==-1) goto out;
        if (func_02017E88(func_021D6064(a),index+54,0)==0) goto out;
        if (*(int *)(a+68)==1) func_021D5A9C((char *)a,0);
        if ((*(u8 **)(a+8))[13]!=6) {
            *(int *)(b+28)=1;
            if (*(int *)(b+20)!=1) {
                b[42]=index;
                func_021DBA54(b+176+index*24,(u8 *)&point1);
                func_0204B404(*(struct Obj **)(b+160),&point1,0);
                func_0204B3DC(*(struct Obj **)(b+160),1);
                if (index==0) func_0204B878(*(struct Obj **)(b+160),3);
                else if (index==3) func_0204B878(*(struct Obj **)(b+160),4);
                else func_0204B878(*(struct Obj **)(b+160),2);
            }
            *(u32 *)(b+44)=*(u32 *)(a+40);
            *(u32 *)(b+48)=*(u32 *)(a+44);
            func_021DBA54(b+176+index*24,(u8 *)&point2);
            func_0204B404(*(struct Obj **)(b+156),&point2,0);
            func_0204B3DC(*(struct Obj **)(b+156),1);
            func_0204B9A0(*(struct Actor **)(b+156));
        }
        a[28]=1;
        func_021DB468(a,b,index,1);
        func_020061E4(1356);
        return;
    }
    if (func_02035C38()==1) {
        if (*(int *)(b+28)!=1) goto out;
        index=func_02035BA4(touch[0]);
        if (*(int *)(b+20)==0) {
            if (index==-1) {
                *(int *)(b+28)=0;
                func_0204B3DC(*(struct Obj **)(b+160),0);
                func_0204B3DC(*(struct Obj **)(b+156),0);
            } else {
                distance=*(u32 *)(b+48)-*(u32 *)(a+44);
                if ((int)distance<0) distance=0U-distance;
                if ((int)distance>8) {
                    func_021DBA78(b+176+b[42]*24,2);
                    *(int *)(b+20)=1;
                    func_0204B3DC(*(struct Obj **)(b+160),0);
                }
            }
        }
        if (*(int *)(b+20)==1) {
            if (index!=-1) {
                if (func_02017E88(func_021D6064(a),index+54,0)==0) goto out;
                func_021DB468(a,b,index,0);
                return;
            }
            func_021DBA78(b+176+b[42]*24,0);
            func_0204B3DC(*(struct Obj **)(b+160),0);
            func_0204B3DC(*(struct Obj **)(b+156),0);
            *(int *)(b+20)=0;
            *(int *)(b+28)=0;
            func_021DB468(a,b,b[41],0);
            b[42]=5;
            return;
        }
    } else {
        if (*(int *)(b+28)==1) {
            func_0204B3DC(*(struct Obj **)(b+160),0);
            func_0204B3DC(*(struct Obj **)(b+156),0);
            if (*(int *)(b+20)==1) {
                if (b[42]!=b[41]) {
                    func_021DB508(a,b,b[42],b[41]);
                    func_020061E4(1357);
                    return;
                }
                *(int *)(b+20)=0;
                func_021DB468(a,b,b[41],0);
            }
        }
    }
out:
    return;
}
