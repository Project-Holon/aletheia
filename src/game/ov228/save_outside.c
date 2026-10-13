/*
 * file:     save_outside.c
 * unit:     yes
 * function: func_021DFC20, func_021DFDB8, func_021DFDC0, func_021DFE00, func_021DFE90, func_021DFE98, func_021DFEAC, func_021DFEB0
 * address:  0x021DFC20
 * region:   ov228
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   BACKUP_SYSTEM_ReadFlash  0x020334CC  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021DFF60     0x021DFF60  data a1
 *   BACKUP_SYSTEM_WriteFlashAsync  0x02033494  arm
 *   BACKUP_SYSTEM_CheckFlashAsync  0x020334B0  arm
 *   func_020071CC 0x020071CC thumb
 *   MYSTERY_DATA_DecryptBuffer 0x0200A50C thumb
 *   MYSTERY_DATA_EncryptBuffer 0x0200A4B8 thumb
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 */
#include "../../matched/include/Obj04656.h"
#include "../../matched/include/Obj14811.h"
#include "../../matched/include/Obj04657.h"
#include "../../matched/include/Obj02268.h"
#include "../../matched/include/Obj26327.h"

struct Sub020071CCCtrl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Blk { u32 w[51]; };

extern void *func_02030734(u32 heap,u32 size,int clear,const char *site,u16 tag);
extern int BACKUP_SYSTEM_ReadFlash(u32 a, u32 b, u32 c);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void MI_CpuCopy8(const void *src,void *dest,u32 size);
extern u32 func_020307B0(void *p);
extern u16 BACKUP_SYSTEM_WriteFlashAsync(u32, void *, u32);
extern int BACKUP_SYSTEM_CheckFlashAsync(u16, u16 *);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void MYSTERY_DATA_DecryptBuffer(void *base, u32 kind);
extern void MYSTERY_DATA_EncryptBuffer(void *base, u32 kind);
void *func_021DFC20(u32 heap);
void func_021DFDB8(void *p);
void func_021DFDC0(u8 *p);
int func_021DFE00(u8 *p);
u8 func_021DFE90(u8 *p);
int func_021DFE98(u8 *p);
void *func_021DFEAC(u8 *p);
void func_021DFEB0(char *p, void *ctrl);
extern const char d_021DFF60[];


/*
 * ov228 entry (save_outside.c): allocate the 0x380-byte work object and a
 * 0x374-byte scratch, read both flash copies (0x7F800, 0x7FC00), check the
 * 0xA10F49AE magic and the CRC over +0xC..0x374, pick the newer valid copy
 * by the +4 counter (0 after 0xFFFFFFFF counts as older), record the state
 * at +0x374 and the loaded flag at +0x378, free the scratch, return the
 * object.  Stack slots follow declaration order in reverse: buf/ok/bad
 * arrays and then obj/sel must be declared in this order.
 */
void *func_021DFC20(u32 heap)
{
    u8 *buf[2];
    int ok[2];
    int bad[2];
    u8 *obj;
    int sel;
    u8 *p;
    int i;

    sel=-1;
    obj=func_02030734(heap,0x380,1,d_021DFF60,0x5b);
    buf[0]=obj;
    buf[1]=func_02030734(heap,0x374,1,d_021DFF60,0x5d);
    for(i=0;i<2;i++){
        ok[i]=0;
        bad[i]=0;
    }
    ok[0]=BACKUP_SYSTEM_ReadFlash(0x7F800,(u32)buf[0],0x374);
    ok[1]=BACKUP_SYSTEM_ReadFlash(0x7FC00,(u32)buf[1],0x374);
    for(i=0;i<2;i++){
        if(ok[i]==1){
            p=buf[i];
            if(((struct Obj14811 *)p)->f0!=0xA10F49AE)ok[i]=0;
            else if(((struct Obj14811 *)p)->f8!=func_0203F1FC(p+12,0x368))bad[i]=1;
        }
    }
    obj[0x378]=0;
    if(ok[0]==0&&ok[1]==0){
    }else if(ok[0]==1&&ok[1]==0){
        if(bad[0]==1)((struct Obj04656 *)obj)->f374=3;
        else sel=0;
    }else if(ok[0]==0&&ok[1]==1){
        if(bad[1]==1)((struct Obj04656 *)obj)->f374=3;
        else sel=1;
    }else if(ok[0]==1&&ok[1]==1){
        if(bad[0]==1&&bad[1]==1)((struct Obj04656 *)obj)->f374=3;
        else if(bad[0]==0&&bad[1]==0){
            if(*(u32 *)(buf[0]+4)>=*(u32 *)(buf[1]+4)||(*(u32 *)(buf[0]+4)==0&&*(u32 *)(buf[1]+4)==0xFFFFFFFF))sel=0;
            else sel=1;
        }else if(bad[0]==0){
            ((struct Obj04656 *)obj)->f374=2;
            sel=0;
        }else{
            sel=1;
            ((struct Obj04656 *)obj)->f374=1;
        }
    }
    if(sel==1)MI_CpuCopy8(buf[1],buf[0],0x374);
    func_020307B0(buf[1]);
    if(sel!=-1)obj[0x378]=1;
    return obj;
}


/*
 * Unlabelled leaf in ov228 (it saves nothing; the listing prints it as
 * .word data after pool_021DFDB4): a one-argument forwarding tail call to
 * the heap free func_020307B0, `ldr r3, [pc]; bx r3` plus the pool word.
 * Its caller is arm9 MYSTERY_DATA_Unload (mystery_data.c), whose MATCH park names
 * this address as its only unwitnessed call.  Integrator: seed ov228
 * 0x021DFDB8.
 */
void func_021DFDB8(void *p)
{
    func_020307B0(p);
}

/*
 * arity: original stores live r0 after F1FC despite its legacy void return; keep returned low halfword.
 */
void func_021DFDC0(u8 *p)
{
    p[0x379]=0;
    if(((struct Obj04657 *)p)->f374==2)p[0x37A]=1;
    else p[0x37A]=0;
    ((struct Obj04657 *)p)->f0=0xA10F49AE;
    ((struct Obj04657 *)p)->f4+=1;
    ((struct Obj04657 *)p)->f8=func_0203F1FC(p+12,0x368);
}


/*
 * Unblocked: BACKUP_SYSTEM_WriteFlashAsync/020334B0 have no traced func_ start (they are
 * ARM tail-call accessors that save no lr), so they are invisible to
 * `sole-ref/code`; both were matched at 0x02033494 and 0x020334B0 and now
 * attest this file's two calls on the `matched` class.
 */
int func_021DFE00(u8 *p)
{
    u16 v;

    switch (p[0x379]) {
    case 0:
    case 2:
        ((struct Obj02268 *)p)->f37C =
            BACKUP_SYSTEM_WriteFlashAsync(p[0x37A] == 0 ? 0x7F800 : 0x7FC00, p, 0x374);
        p[0x379] = p[0x379] + 1;
        break;
    case 1:
    case 3:
        if (BACKUP_SYSTEM_CheckFlashAsync(((struct Obj02268 *)p)->f37C, &v) == 1) {
            p[0x37A] = p[0x37A] ^ 1;
            p[0x379] = p[0x379] + 1;
        }
        break;
    default:
        ((struct Obj02268 *)p)->f374 = 0;
        p[0x378] = 1;
        return 1;
    }
    return 0;
}


/*
 * Unlabelled leaf in ov228: returns the byte at +0x378 of the overlay's
 * work object (0x378 built as 0xDE << 2).  Caller: arm9 MYSTERY_DATA_Load
 * (mystery_data.c).  Integrator: seed ov228 0x021DFE90.
 */
u8 func_021DFE90(u8 *p)
{
    return p[0x378];
}


int func_021DFE98(u8 *p)
{
    if (((struct Obj26327 *)p)->f374 == 3)
        return 1;
    return 0;
}


void *func_021DFEAC(u8 *p)
{
    return p + 0xc;
}

void func_021DFEB0(char *p, void *ctrl)
{
    u8 *buf;
    u8 *src;
    int i;
    int j;
    buf = func_020071CC(ctrl, 0x22);
    src = (u8 *)p + 0xC;
    MYSTERY_DATA_DecryptBuffer(buf, 1);
    MYSTERY_DATA_DecryptBuffer(src, 0);
    for (i = 0; i < 256; i++)
        buf[i] = src[i];
    for (j = 0; j < 3; j++)
        *(struct Blk *)(buf + 0x100 + j * 0xCC) = *(struct Blk *)(src + 0x100 + j * 0xCC);
    MYSTERY_DATA_EncryptBuffer(buf, 1);
    MYSTERY_DATA_EncryptBuffer(src, 0);
}
