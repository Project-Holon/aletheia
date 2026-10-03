/*
 * function: func_021F1A1C
 * address: 0x021F1A1C
 * packet: pkt_ov194_021F1A1C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 478 instruction bytes; 021F1BFA is two-byte zero alignment before021F1BFC.
 * lever: const Rect source schedules the loads ahead of argument stores; signed y destinations avoid an extra unsigned truncation pair (484/224 to482/157 toEXACT*478).
 * symbols:
 *   func_020413B0 0x020413B0 arm
 *   func_020355C4 0x020355C4 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020409B4 0x020409B4 arm
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Rect {int left,top,right,bottom;} Rect;
extern void func_020413B0(unsigned,u8,u8,u8,u8,u8);
extern u8 func_020355C4(void);
extern void func_0204B9A0(void *),func_0204B3DC(void *,unsigned);
extern void func_020409B4(unsigned),func_02082BCC(void *,int,int);
void func_021F1A1C(char *p,int mode,const Rect *rect,int flag,int selected)
{
    int x;
    short y;
    *(int *)(p+0x98)=0;
    *(int *)(p+0x94)=mode;
    *(int *)(p+0x9c)=flag;
    *(int *)(p+0xa0)=selected;
    func_020413B0(2,0,0,32,24,1);
    func_020413B0(1,0,0,32,24,1);
    if(flag!=0 && selected==3) {
        func_020413B0(1,3,16,4,3,4);
        func_020413B0(1,23,16,4,3,4);
    }
    x=(selected+1)*3;
    func_020413B0(1,x,20,3,3,4);
    func_020413B0(2,x,20,3,3,4);
    if(rect && mode!=0) {
        *(Rect *)(p+0x84)=*rect;
        if(mode==2) {
            func_020413B0(2,rect->left,rect->top,rect->right-rect->left,rect->bottom-rect->top,mode+1);
            func_020413B0(1,rect->left,rect->top,rect->right-rect->left,rect->bottom-rect->top,mode+1);
        }
        if(func_020355C4()==0) {
            *(u16 *)(p+0xac)=rect->left*8+7;
            y=rect->top*8+(rect->bottom-rect->top)*4-3;
            *(short *)(p+0xae)=y;
            *(u16 *)(p+0xb0)=rect->right*8-7;
            *(short *)(p+0xb2)=y;
            func_0204B9A0(*(void **)(p+0xa4));
            func_0204B9A0(*(void **)(p+0xa8));
            func_0204B3DC(*(void **)(p+0xa4),1);
            func_0204B3DC(*(void **)(p+0xa8),1);
        }
    }
    if(mode==0 || func_020355C4()==1) {
        func_0204B3DC(*(void **)(p+0xa4),0);
        func_0204B3DC(*(void **)(p+0xa8),0);
    }
    func_020409B4(2);
    func_020409B4(1);
    if(mode!=0) {
        func_02082BCC(p+0x60,0,32);
        *(u16 *)(p+0x80)=0;
        *(int *)(p+0x98)=1;
    }
}
