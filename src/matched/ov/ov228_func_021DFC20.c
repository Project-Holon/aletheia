/*
 * function: func_021DFC20
 * address:  0x021DFC20
 * packet:   pkt_021DFC20
 * region:   ov228
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020334CC  0x020334CC  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021DFF60     0x021DFF60  data a1
 *
 * ov228 entry (save_outside.c): allocate the 0x380-byte work object and a
 * 0x374-byte scratch, read both flash copies (0x7F800, 0x7FC00), check the
 * 0xA10F49AE magic and the CRC over +0xC..0x374, pick the newer valid copy
 * by the +4 counter (0 after 0xFFFFFFFF counts as older), record the state
 * at +0x374 and the loaded flag at +0x378, free the scratch, return the
 * object.  Stack slots follow declaration order in reverse: buf/ok/bad
 * arrays and then obj/sel must be declared in this order.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heap,u32 size,int clear,const char *site,u16 tag);
extern int func_020334CC(u32 ofs,void *dest,u32 size);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_02082D44(const void *src,void *dest,u32 size);
extern void func_020307B0(void *p);
extern const char d_021DFF60[];

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
    ok[0]=func_020334CC(0x7F800,buf[0],0x374);
    ok[1]=func_020334CC(0x7FC00,buf[1],0x374);
    for(i=0;i<2;i++){
        if(ok[i]==1){
            p=buf[i];
            if(*(u32 *)p!=0xA10F49AE)ok[i]=0;
            else if(*(u16 *)(p+8)!=func_0203F1FC(p+12,0x368))bad[i]=1;
        }
    }
    obj[0x378]=0;
    if(ok[0]==0&&ok[1]==0){
    }else if(ok[0]==1&&ok[1]==0){
        if(bad[0]==1)*(u32 *)(obj+0x374)=3;
        else sel=0;
    }else if(ok[0]==0&&ok[1]==1){
        if(bad[1]==1)*(u32 *)(obj+0x374)=3;
        else sel=1;
    }else if(ok[0]==1&&ok[1]==1){
        if(bad[0]==1&&bad[1]==1)*(u32 *)(obj+0x374)=3;
        else if(bad[0]==0&&bad[1]==0){
            if(*(u32 *)(buf[0]+4)>=*(u32 *)(buf[1]+4)||(*(u32 *)(buf[0]+4)==0&&*(u32 *)(buf[1]+4)==0xFFFFFFFF))sel=0;
            else sel=1;
        }else if(bad[0]==0){
            *(u32 *)(obj+0x374)=2;
            sel=0;
        }else{
            sel=1;
            *(u32 *)(obj+0x374)=1;
        }
    }
    if(sel==1)func_02082D44(buf[1],buf[0],0x374);
    func_020307B0(buf[1]);
    if(sel!=-1)obj[0x378]=1;
    return obj;
}
