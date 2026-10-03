/*
 * function: func_021C270C
 * address: 0x021C270C
 * packet: pkt_ov208_021C270C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BC3B4 0x021BC3B4 thumb ov208
 *   func_021BC3B8 0x021BC3B8 thumb ov208
 *   func_021BC3BC 0x021BC3BC thumb ov208
 *   func_021BC3A4 0x021BC3A4 thumb ov208
 *   func_021C2C44 0x021C2C44 thumb ov208
 *   func_021C2E6C 0x021C2E6C thumb ov208
 *   func_021C3218 0x021C3218 thumb ov208
 *   func_021C3280 0x021C3280 thumb ov208
 *   func_021C3354 0x021C3354 thumb ov208
 *   func_021C3378 0x021C3378 thumb ov208
 *   func_021BC9BC 0x021BC9BC thumb ov208
 *   func_021BC844 0x021BC844 thumb ov208
 *   func_021C2DE0 0x021C2DE0 thumb ov208
 *   func_021C35DC 0x021C35DC thumb ov208
 *   func_021BC758 0x021BC758 thumb ov208
 *   func_021BC718 0x021BC718 thumb ov208
 *   func_021BC4F4 0x021BC4F4 thumb ov208
 *   func_021C3AA8 0x021C3AA8 thumb ov208
 *   func_021BC6D8 0x021BC6D8 thumb ov208
 *   func_021BDAD0 0x021BDAD0 thumb ov208
 *   func_021BDAAC 0x021BDAAC thumb ov208
 *   func_021BDAD4 0x021BDAD4 thumb ov208
 *   func_021BDBB8 0x021BDBB8 thumb ov208
 *   func_021BDC48 0x021BDC48 thumb ov208
 *   func_021BDC14 0x021BDC14 thumb ov208
 *   func_021BE840 0x021BE840 thumb ov208
 *   func_021BE82C 0x021BE82C thumb ov208
 *   func_021BE844 0x021BE844 thumb ov208
 *   func_021BC6C8 0x021BC6C8 thumb ov208
 *   func_021BDBA0 0x021BDBA0 thumb ov208
 *   func_021BC6F8 0x021BC6F8 thumb ov208
 *   func_021BE854 0x021BE854 thumb ov208
 *   func_021BDAE8 0x021BDAE8 thumb ov208
 *   func_021C2BF4 0x021C2BF4 thumb ov208
 *   func_021C3514 0x021C3514 thumb ov208
 *   func_021C3B14 0x021C3B14 thumb ov208
 *   func_021BC508 0x021BC508 thumb ov208
 *   func_021C3380 0x021C3380 thumb ov208
 *   func_021C3650 0x021C3650 thumb ov208
 *   func_021C301C 0x021C301C thumb ov208
 *   func_021C3318 0x021C3318 thumb ov208
 *   func_021BC99C 0x021BC99C thumb ov208
 *   func_021BC46C 0x021BC46C thumb ov208
 *   func_021BC678 0x021BC678 thumb ov208
 *   func_021C2C1C 0x021C2C1C thumb ov208
 *   func_02040618 0x02040618 arm
 *   func_020414AC 0x020414AC arm
 *   func_0204047C 0x0204047C arm
 *   func_0204B688 0x0204B688 arm
 *   func_02012BF8 0x02012BF8 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor; struct Ov208Win; struct Ov208PalFade; struct Ov208Scene; struct Ov208Fade; struct Ov208Icon; struct Ov208Blend; struct Key;
extern void *func_021BC3B4(int);
extern void *func_021BC3B8(int);
extern u16 func_021BC3BC(char *);
extern int func_021BC3A4(int);
extern void func_02040618(u32,u32,u32);
extern void func_020414AC(u8);
extern void func_0204047C(int,u16);
extern void func_0204B688(struct Actor *,u32);
extern int func_02012BF8(int,int);
extern void func_021C2C44(u16 *,u8 *,int);
extern void func_021C2E6C(u16 *,u8 *,int,u32);
extern void func_021C3218(u16 *,u8 *,int);
extern void func_021C3280(u16 *,u8 *,struct Key *);
extern void func_021C3354(u16 *,u8 *,int);
extern void func_021C3378(u16 *,u8 *,int,int,u16);
extern u32 func_021BC9BC(int,u16,u8,u8,u8,u8,u32,u32,u32,u32,u32);
extern struct Ov208Win *func_021BC844(u16,u32,u8,u8,u8);
extern void func_021C2DE0(void *,u8 *,void *,int,u16);
extern void func_021C35DC(u16 *,u8 *,int);
extern void func_021BC758(struct Ov208PalFade *);
extern void func_021BC718(u32);
extern void func_021BC4F4(int,u32);
extern void func_021C3AA8(void *,u8 *,int);
extern void func_021BC6D8(u32);
extern int func_021BDAD0(struct Ov208Fade *);
extern void func_021BDAAC(struct Ov208Scene *,u32,u32,u32);
extern void func_021BDAD4(struct Ov208Fade *,int);
extern void func_021BDBB8(struct Ov208Scene *,u32);
extern void func_021BDC48(struct Ov208Scene *,u32);
extern void func_021BDC14(void *,int);
extern int func_021BE840(struct Ov208Icon *);
extern void func_021BE82C(struct Ov208Icon *,int);
extern void func_021BE844(struct Ov208Icon *);
extern int func_021BC6C8(u32);
extern void func_021BDBA0(struct Ov208Scene *);
extern void func_021BC6F8(u32);
extern void func_021BE854(struct Ov208Icon *);
extern void func_021BDAE8(void *,int);
extern void func_021C2BF4(void *,u8 *,void *);
extern void func_021C3514(u16 *,u8 *,int);
extern void func_021C3B14(void *,u8 *,int);
extern void func_021BC508(int,u32 *);
extern void func_021C3380(u16 *,u8 *,int);
extern void func_021C3650(u16 *,u8 *,int);
extern void func_021C301C(u16 *,u8 *,int);
extern void func_021C3318(u16 *,u8 *,int);
extern void func_021BC99C(u32);
extern void func_021BC46C(struct Ov208Blend *,struct Ov208Blend *);
extern void func_021BC678(u32);
extern void func_021C2C1C(u16 *,u8 *,int);
#define W(o) (*(u32 *)(p+(o)))
/* Explicit caller r2 loads preserve trailing arguments on setup/update helpers. */
int func_021C270C(void *unused,int *seq,u16 *heap,u8 *p,int key)
{
    void *scene;
    struct Ov208Icon *icon;
    u8 i;
    int ready;
    scene=func_021BC3B4(key);
    icon=func_021BC3B8(key);
    switch(*seq){
    case 0:
        *seq=1;
        for(i=0;i<=7;i++){
            if(i!=1 && i!=5){
                func_02040618(i,0,0);
                func_02040618(i,3,0);
                func_020414AC(i);
            }
        }
        func_0204047C(2,1);
        func_0204047C(3,2);
        func_0204047C(0,3);
        func_0204047C(6,1);
        func_0204047C(4,3);
        func_021C2C44(heap,p,key);
        func_021C2E6C(heap,p,key,W(0x5c));
        func_0204B688((struct Actor *)(*(u32 *)((p+W(0x5c)*4)+0x54)),1);
        func_021C3218(heap,p,key);
        func_021C3280(heap,p,(struct Key *)key);
        func_021C3354(heap,p,key);
        func_021C3378(heap,p,key,0,0);
        W(0x78)=func_021BC9BC(0,*heap,2,1,0,5,0x9f,1,0xb,0x2a,0);
        W(0x7c)=(u32)func_021BC844(*heap,2,0,2,3);
        W(0x80)=(u32)func_021BC844(*heap,2,4,1,2);
        func_021C2DE0(heap,p,(void *)key,0,0);
        func_021C35DC(heap,p,key);
        func_021BC758((struct Ov208PalFade *)W(0xc8));
        func_021BC718(W(0xc8));
        break;
    case 1:
        *seq=2;
        func_021BC4F4(0,W(0xc0));
        func_021BC4F4(1,W(0xc4));
        func_021C3AA8(heap,p,key);
        break;
    case 2:
        *seq=3;
        func_021BC6D8(W(0xc8));
        if(func_021BDAD0(scene)!=2){
            func_021BDAAC(scene,0,2,func_021BC3BC((char *)key)>1);
            func_021BDAD4(scene,0);
        }else func_021BDBB8(scene,2);
        func_021BDC48(scene,0);
        func_021BDC14(scene,func_02012BF8(func_021BC3A4(key),0x13));
        if(func_021BE840(icon)!=2){
            func_021BE82C(icon,2);
            func_021BE844(icon);
        }
        break;
    case 3:
        if(func_021BC6C8(W(0xc8))==0 && func_021BDAD0(scene)==2 && func_021BE840(icon)==2){
            func_021BDBA0(scene);
            func_021BDC48(scene,1);
            *seq=4;
        }
        break;
    case 4:
        if(W(0xcc)!=0){
            *seq=5;
            func_021BC6F8(W(0xc8));
            func_021BE854(icon);
            if(W(0xcc)==2)func_021BDAE8(scene,0);
            func_021C2BF4(heap,p,(void *)key);
        }else func_021C3514(heap,p,key);
        break;
    case 5:
        ready=0;
        if(func_021BC6C8(W(0xc8))==0 && func_021BE840(icon)==0){
            if(W(0xcc)==2){
                if(func_021BDAD0(scene)==0)ready=1;
            }else ready=1;
        }
        if(ready)*seq=6;
        break;
    case 6:
        *seq=7;
        func_021C3B14(heap,p,key);
        func_021BC508(0,(u32 *)W(0xc0));
        func_021BC508(1,(u32 *)W(0xc4));
        break;
    case 7:
        return 1;
    }
    if(*seq>=3){
        func_021C3380(heap,p,key);
        func_021C3650(heap,p,key);
        func_021C301C(heap,p,key);
    }
    if(*seq>=2){
        func_021C3318(heap,p,key);
        func_021BC99C(W(0x7c));
        func_021BC99C(W(0x80));
    }
    func_021BC46C((struct Ov208Blend *)W(0xc0),(struct Ov208Blend *)W(0xc4));
    func_021BC678(W(0xc8));
    func_021C2C1C(heap,p,key);
    return 0;
}
