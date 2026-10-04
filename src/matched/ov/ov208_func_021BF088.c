/*
 * function: func_021BF088
 * address: 0x021BF088
 * packet: pkt_ov208_021BF088
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC3B4 0x021BC3B4 thumb ov208
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_021BF280 0x021BF280 thumb ov208
 *   func_0204B878 0x0204B878 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_020355D8 0x020355D8 arm
 *   func_021BDC48 0x021BDC48 thumb ov208
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
struct Obj;
struct Ov208Scene;
extern int func_021BC3B4(int *p);
extern u32 func_0203633C(void);
extern u32 func_020362DC(void);
extern u32 func_0204B3F4(struct Obj *);
extern void func_021BF280(void *,char *,void *,int);
extern void func_0204B878(struct Obj *,u16);
extern void func_020061E4(u32);
extern void func_020355D8(u8);
extern void func_021BDC48(struct Ov208Scene *,u32);
int func_021BF088(void *first,char *p,int key)
{
    void *scene;
    int changed;
    u32 buttons,press;
    u8 i,next;
    scene=(void *)func_021BC3B4((int *)key);
    changed=0;
    if(*(int *)(p+0x94)==6) {
        buttons=func_0203633C();
        press=func_020362DC();
        if(*(int *)(p+0x98)==6) {
            if((buttons&0x300)||(press&1)) {
                for(i=0;i<6;i++) {
                    if(func_0204B3F4(*(struct Obj **)((u32)p+(u32)i*20+0x1c))!=0) {
                        *(int *)(p+0x94)=i; changed=1; break;
                    }
                }
            }
        } else if((buttons&0x100)||(press&1)) {
            for(i=1;i<6;i++) {
                next=(*(int *)(p+0x98)+i)%6;
                if(func_0204B3F4(*(struct Obj **)((u32)p+(u32)next*20+0x1c))!=0) {
                    *(int *)(p+0x94)=next; changed=1; break;
                }
            }
        } else if(buttons&0x200) {
            for(i=1;i<6;i++) {
                next=(*(int *)(p+0x98)+6-i)%6;
                if(func_0204B3F4(*(struct Obj **)((u32)p+(u32)next*20+0x1c))!=0) {
                    *(int *)(p+0x94)=next; changed=1; break;
                }
            }
        }
    }
    if(changed!=0) {
        func_021BF280(first,p,(void *)key,*(int *)(p+0x94));
        *(u32 *)((u32)p+*(u32 *)(p+0x94)*20+0x2c)=1;
        func_0204B878(*(struct Obj **)((u32)p+*(u32 *)(p+0x94)*20+0x1c),*(u16 *)((u32)p+*(u32 *)(p+0x94)*20+0x26));
        func_020061E4(0x54a);
        func_020355D8(0);
        func_021BDC48(scene,0);
    }
    return changed;
}
