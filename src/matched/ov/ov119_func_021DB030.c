/*
 * function: func_021DB030
 * address: 0x021DB030
 * packet: pkt_ov119_021DB030
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the 0x1080 halfword is signed; u16 pools 0xffff, s16 derives -1 from zero.
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021E4E64 0x021E4E64 thumb ov119
 *   func_021E6700 0x021E6700 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DAFB8 0x021DAFB8 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 */
typedef short s16;
extern int func_020279E8(int),func_02027A04(int);
extern void func_021E12F8(void *),func_021E1098(void *),func_021E4E64(int,void *,int),func_021E6700(void *);
extern void func_021D8E84(void *,int),func_021DAFB8(void *),func_021DBE70(void *);
void func_021DB030(char *p) {
 int v;
 if(func_020279E8(*(int *)(p+0x64c))) {
  v=func_02027A04(*(int *)(p+0x64c));func_021E12F8(p);*(int *)(p+0x64c)=0;
  switch(v) {
  case 0:func_021D8E84(p,(int)func_021DAFB8);return;
  case 1:func_021E1098(p);func_021D8E84(p,(int)func_021DBE70);
   *(s16 *)(p+0x1080)=-1;func_021E4E64(*(int *)(p+0x828),p,0);func_021E6700(p);return;
  }
 }
}
