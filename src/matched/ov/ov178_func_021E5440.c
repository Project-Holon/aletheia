/*
 * function: func_021E5440
 * address: 0x021E5440
 * packet: pkt_ov178_021E5440
 * region: ov178
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02031324 0x02031324 arm
 *   func_021E56F4 0x021E56F4 thumb ov178
 *   func_021E57E0 0x021E57E0 thumb ov178
 *   d_02FFFC3C 0x02FFFC3C data a4
 */
extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern char *func_0203159C(void *,int,int);
extern void func_02082BCC(void *,int,int);
extern void *func_02031324(unsigned);
extern void func_021E56F4(void *,void *,void *);
extern void func_021E57E0(int *,int *,char *);
extern unsigned d_02FFFC3C;
typedef struct {unsigned words[9];} Copy;
int func_021E5440(void *handle,int unused,char *q)
{
 char *p;
 func_0203064C(1,0x58,0x30000);
 p=func_0203159C(handle,0xFC,0x58);
 func_02082BCC(p,0,0xFC);
 *(Copy *)(p+0xD4)=*(Copy *)q;
 *(unsigned short *)(p+0xF8)=0x58;
 *(void **)(p+0xD0)=func_02031324(*(unsigned short *)(p+0xF8));
 *(unsigned *)(p+4)=*(unsigned *)(q+4);
 func_021E56F4(q,p,p+8);func_021E57E0((int *)q,(int *)p,p+0xA0);
 *(unsigned char *)(p+0xC8)=0;
 *(unsigned *)(p+0xCC)=d_02FFFC3C;
 *(unsigned *)p=0;*(unsigned *)(q+0x20)=0;
 return 1;
}
