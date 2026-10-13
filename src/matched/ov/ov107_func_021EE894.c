/*
 * function: func_021EE894
 * address: 0x021EE894
 * packet: pkt_ov107_021EE894
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * closed 2026-10-05: the unlabelled leaves it calls are now matched files, so every relocation resolves.
 * checks: 1 own overlay definitions and SDK bodies read; strict current rule conflicts with historical used-r0 declarations for own-void 021F15B0 and02078C28, and extra original zero to021F19E4. Original caller loads File* before78C28 and consumes r0 afterward; park owner definition/listing discrepancy, never diverge for a match. 2 fresh EF79C/EFFB0/EF444 flow/prototype neighbours. 3 long result unchanged1564/913. 4 boolean-arm, shared-goto, dense-switch, branch-range and declared72-byteFile idioms read. 5 unfiltered idiom directory and neighbours refreshed. Next: resolve own definitions before case9 call-in-each-arm hypothesis; scheduling cap consumed.
 * residual: W77 final retry: five fixed runs; 1564 compiled versus actual main1560 (+4), 913 concrete bytes. Handed1568 includes separately matched8-byte021EEEAC; no duplicate unit. Case9 select, default label, SDK declarations and long result unchanged; duplicate failure helper worsened997. 119/126 relocations resolve, 1008/1010/1040/1050/1064/EFE3C remain overlay wildcard sites. Prior permuter300 consumed and follower extent also excluded; no repeated search.
 * search: R3 first permuter300 spent; then-emitted macro-free baseline909 agreed one. Size-first best1568/1050 was worse and rejected; extent still includes the already matched 8-byte stub despite compiling only main. Search not repeated in W76.
 * retry: Wave59 R3: 4 fixed-flag runs plus permuter300; single retry completed.
 * extent: 021EEEAC already matched separately by pkt_ov107_021EEEAC; file only main, no duplicate unit/stub. Unowned EEEB4 begins after handed1568 bytes.
 * note 2026-10-05 (P18L6): extent is 1560 B (not 98 B); the lane size was a label gap. Re-read: the 913 B residue is mostly branch-range fixup shape. Original default `bhi` shares the `beq L; b tail` stub after case 3; compiled emits `bls; b` at the dispatch (+4 B) and `bne island` in case 3. Case blocks from case 19 on are also ordered differently (cases 20..33 tail region). Tried: case 3 written `if(r!=1) break; return 1;` (913, unchanged); explicit `default: break;` (913, unchanged). Callee check: matched ov107 func_021F1060 returns a pointer (p->f0C) while this draft compares its result with ints and ov029 declares it int, a conflict not resolved; func_021F15B0 is matched void but its result feeds CLACT_DrawSystem (already noted). Not repeated: permuter, size-first. Status stays DIFF.
 * note recoup 2026-10-05 P30R10: DIFF -> MATCH, 1560/1560 bytes, all code bytes equal; only relocation witnesses missing (callees 021F1008 and 021F1010 are Thumb veneers, 021F1040, 021F1050, 021F1064 and 021EFE3C are small ov107 leaves with no matched file). The old 913-byte residue was branch-island layout caused by real source differences, found by comparing mnemonic streams: (1) cases 25 and 26 sit after case 29 in the original block order (24, 27, 28, 29, 25, 26, 30); (2) case 27 jumps into the failure block tail: `if(f11F0(O,18,0)!=1)break;goto fail_tail;` with `fail_tail:` before `func_021F1028(O);W(32)=28;` (the `==1 goto` form leaves a dead `b`); (3) case 17 second arm had an extra func_021F1704(M,7,..) call in the draft, removed (cross-jumping hid it); (4) the three constant ternaries `W(32)=p[40]==0?a:b` (cases 1, 11, 29) are if/else with a store in each arm; (5) case 9 calls GFL_NET_RestartWithDefaultTimeout(0,H(0)) and GFL_NET_RestartWithDefaultTimeout(1,H(0)) in each arm; (6) case 23 keeps the func_02007774 result in a `u16 cnt` local (a (u16) cast at the call gave an extra adds). Tried without effect: explicit default after case 3 (913), all six per-function pragmas (913 each), `p[40]!=0` argument, u16 third parameter on func_021F11F0, u16 return type on func_02007774 (drops the truncation). Also MATCH with --lang c. Next: file ov107 witnesses for 021F1040 (p->f04==5), 021F1050 (p->f04<6), 021EFE3C (empty void), 021F1064 (flag clear) and veneers 021F1008/021F1010 via integrator label seeding.
 * symbols:
 *   func_021F0E6C 0x021F0E6C thumb ov107
 *   func_021EFC1C 0x021EFC1C thumb ov107
 *   func_021F1628 0x021F1628 thumb ov107
 *   func_021F1704 0x021F1704 thumb ov107
 *   func_021F1A58 0x021F1A58 thumb ov107
 *   func_021F1B24 0x021F1B24 thumb ov107
 *   func_021F1B14 0x021F1B14 thumb ov107
 *   func_021F19E4 0x021F19E4 thumb ov107
 *   func_021F1A2C 0x021F1A2C thumb ov107
 *   func_021F1898 0x021F1898 thumb ov107
 *   func_021F1A24 0x021F1A24 thumb ov107
 *   func_021EF588 0x021EF588 thumb ov107
 *   func_021EF79C 0x021EF79C thumb ov107
 *   func_021EF74C 0x021EF74C thumb ov107
 *   func_021F0EFC 0x021F0EFC thumb ov107
 *   func_021F1008 0x021F1008 thumb ov107
 *   func_021F1018 0x021F1018 thumb ov107
 *   func_021F1050 0x021F1050 thumb ov107
 *   func_021F1370 0x021F1370 thumb ov107
 *   func_021F1060 0x021F1060 thumb ov107
 *   func_021F1174 0x021F1174 thumb ov107
 *   func_021F1184 0x021F1184 thumb ov107
 *   func_021F11BC 0x021F11BC thumb ov107
 *   func_021F11F0 0x021F11F0 thumb ov107
 *   func_021F11E8 0x021F11E8 thumb ov107
 *   func_021F1064 0x021F1064 thumb ov107
 *   func_021F1028 0x021F1028 thumb ov107
 *   func_021F1040 0x021F1040 thumb ov107
 *   func_021F0FE8 0x021F0FE8 thumb ov107
 *   func_021F1010 0x021F1010 thumb ov107
 *   func_021F15B0 0x021F15B0 thumb ov107
 *   func_021EFD24 0x021EFD24 thumb ov107
 *   func_021EFE40 0x021EFE40 thumb ov107
 *   func_021EFE3C 0x021EFE3C thumb ov107
 *   func_021EFFB0 0x021EFFB0 thumb ov107
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_020461E4 0x020461E4 arm
 *   func_020788AC 0x020788AC arm
 *   func_02078C18 0x02078C18 arm
 *   func_02078B44 0x02078B44 arm
 *   FS_GetLength 0x02078C28 arm
 *   func_02078B70 0x02078B70 arm
 *   func_02078A80 0x02078A80 arm
 *   func_02034714 0x02034714 arm
 *   func_02030734 0x02030734 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   GAME_DATA_IsSaving 0x02012E40 thumb
 *   GAME_DATA_SaveCancel 0x02012E08 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_0202EB44 0x0202EB44 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   func_0200C184 0x0200C184 thumb
 *   func_0200575C 0x0200575C thumb
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   GAME_DATA_GetBoxManager 0x0201293C thumb
 *   func_02007774 0x02007774 thumb
 *   d_021F6E08 0x021F6E08 data a4
 *   d_021F6E0C 0x021F6E0C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { FS_OK=0, FS_ERROR=1 } FSResult;
typedef struct File {
 struct File *next; void *userdata; void *arc; u32 stat;
 void *argument; FSResult error; void *queue[2];
 u8 reserved1[16]; u8 arg[24];
} File;
extern void func_021F0E6C(void *),func_021EFC1C(u8 *,int);
extern u8 GAME_DATA_IsSaving(const u8 *);
typedef signed int     s32;
struct BigObj;
struct Bits;
struct Blk34;
struct FSFile;
struct Sub02008C20Obj;
extern void GAME_DATA_SaveCancel(char *p);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 WIPE_SYS_EndCheck(void);
extern int func_0202EB44(void);
extern signed char func_02012FFC(void);
extern void GFL_USE_FadeOutBgm(u32),GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern void func_021F1628(void *,int);
extern void func_021F1704(void *,int,int);
extern void func_021F1A58(char *p, int a);
extern void func_021F1B24(void *,int);
extern int func_021F1B14(void *),func_021F1A2C(void *);
extern void func_021F19E4(void *,int);
extern void func_021F1898(void *);
extern void func_021F1A24(u8 *p);
extern void func_021EF588(u8 *),func_021EF74C(u8 *),func_021F0EFC(void *);
extern int func_021EF79C(u8 *);
extern int func_021F1008(void *);
extern int func_021F1050(int *p);
extern void func_021F1018(u8 *p);
extern u32 func_020461E4(int);
extern u32 func_0200C184(struct Blk34 *p);
extern int func_021F1370(void *,void *),func_021F1060(void *);
extern void *func_0200575C(u32);
extern void func_020788AC(File *);
extern int func_02078C18(File *,void *),func_02078A80(File *);
typedef enum { SEEK_SET=0, SEEK_CUR=1, SEEK_END=2 } SeekOrigin;
extern int func_02078B44(struct FSFile *file, long offset, int origin);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
extern u32 FS_GetLength(struct FSFile *a0);
extern u8 d_021F6E08[],d_021F6E0C[];
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021F1174(int a, int b, int c);
extern void func_021F1184(void *);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 GAME_DATA_GetBoxManager(const struct BigObj *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern int func_02007774(void *);
extern int func_021F11BC(void *);
extern int func_021F11E8(struct Bits *a);
extern int func_021F11F0(void *,u8,u32);
extern void func_021EFD24(u8 *),func_021EFE40(u8 *),func_021EFE3C(u8 *),func_021EFFB0(u8 *);
extern void func_021F1064(unsigned char *p);
extern void func_021F1028(int *p);
extern void func_021F0FE8(void *);
extern int func_021F1040(int *p);
extern int func_021F1010(void *);
extern void *func_021F15B0(void *);
extern void CLACT_DrawSystem(void *);
extern void CLACT_VBlankSystem(void);
#define P(k) (*(void **)(p+(k)))
#define W(k) (*(u32 *)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
#define O P(12)
#define M P(104)
#define SAVE (*(void **)((u8 *)P(8)+4))
typedef enum { Phase0=0,Phase33=33 } Phase;
#define PHASE (*(Phase *)(p+32))
static inline void load_payload(u8 *p) {
 File file; void *name;
 name=func_0200575C(142);func_020788AC(&file);
 if(!func_02078C18(&file,name))func_02034714((const char *)d_021F6E08,0,(const char *)d_021F6E08);
 func_02078B44((struct FSFile *)(&file),0,0);W(100)=FS_GetLength((struct FSFile *)(&file));
 P(96)=func_02030734(H(0),W(100),1,(const char *)d_021F6E0C,660);
 func_02078B70((struct FSFile *)(&file),P(96),W(100));
 if(!func_02078A80(&file))func_02034714((const char *)d_021F6E08,0,(const char *)d_021F6E08);
 W(32)=13;
}
int func_021EE894(u8 *p) {
 u32 result;
 func_021F0E6C(O);
 if(W(16)==1 && W(32)!=2 && W(32)!=3) {
  W(24)=GAME_DATA_IsSaving(SAVE);
  if(W(24)==1)GAME_DATA_SaveCancel(SAVE);
  W(32)=2;func_021EFC1C(p,3);
 }
 switch(PHASE) {
 case 0:WIPE_SYS_Start(0,1,1,0,6,1,H(0));W(32)=1;break;
 case 1:
  if(WIPE_SYS_EndCheck()==1) {
   if(func_0202EB44()==1){if(p[40]==0)W(32)=7;else W(32)=4;}
   else {func_021F1628(M,5);func_021F1A58(M,func_02012FFC());func_021F1B24(M,1);W(32)=33;}
  }break;
 case 2:
  if(*(u8 *)P(8)==0)WIPE_SYS_Start(0,0,0,0,6,1,H(0));
  else {WIPE_SYS_Start(0,0,0,32767,6,1,H(0));GFL_USE_FadeOutBgm(6);}
  W(32)=3;break;
 case 3:if(WIPE_SYS_EndCheck()==1)return 1;break;
 case 4:func_021F1628(M,5);func_021F1704(M,43,func_02012FFC());W(32)=5;break;
 case 5:if(func_021F1B14(M)==1){func_021F19E4(M,0);W(32)=6;}break;
 case 6:
  result=func_021F1A2C(M);
  if(result==1){W(32)=7;func_021F1898(M);func_021F1A24(M);}
  else if(result==2)W(32)=2;break;
 case 7:func_021EF588(p);W(32)=8;break;
 case 8:if(func_021EF79C(p)==1)W(32)=9;break;
 case 9:
  func_021EF74C(p);
  if(W(48)==1){W(32)=10;H(42)=0;func_021F0EFC(O);if(p[40]==0)GFL_NET_RestartWithDefaultTimeout(0,H(0));else GFL_NET_RestartWithDefaultTimeout(1,H(0));}
  else W(32)=2;break;
 case 10:if(func_021F1008(O)==1){W(32)=11;func_021F1018(O);}break;
 case 11:
  H(42)++;
  if(H(42)>=1800){func_021EFC1C(p,3);W(32)=30;}
  else if(func_021F1050(O)==1){
   W(88)=func_02012FFC();p[94]=func_020461E4(W(88));
   if(p[40]==0)H(92)=func_0200C184(P(76));
   if(func_021F1370(O,p+88)==1){if(p[40]==0)W(32)=12;else W(32)=32;}
  }break;
 case 12:load_payload(p);break;
 case 13:W(32)=14;break;
 case 14:
  if(func_021F1060(O)==10)goto failure;
  if(func_021F1060(O)==2){
   if(W(44)==0){W(44)=1;func_021F1174((int)O,(int)P(96),W(100));}
   func_021F1704(M,2,func_02012FFC());W(32)=15;
  }break;
 case 15:
  if(func_021F1060(O)==3){func_021F1704(M,3,func_02012FFC());W(32)=16;}
  else if(func_021F1060(O)==13){func_021EFC1C(p,4);func_021F1704(M,8,func_02012FFC());func_021F1028(O);W(32)=28;}
 case 16:
  if(func_021F1060(O)==4){func_021F1184(O);func_021F1704(M,4,func_02012FFC());W(32)=17;}break;
 case 17:
  if(func_021F1060(O)==5){func_02008DF0(GAME_DATA_GetTrainerRecord(SAVE),120);H(58)++;W(32)=18;}
  else if(func_021F1060(O)==8){func_02008DF0(GAME_DATA_GetTrainerRecord(SAVE),120);H(58)++;func_021EFC1C(p,2);W(32)=23;}
  break;
 case 18:if(func_021F11BC(O)==1 && func_021F11F0(O,0,0)==1)W(32)=19;break;
 case 19:
  if(func_021F11E8(O)==1 || p[40]==1){
   if(func_021F1060(O)==6)W(32)=20;
   else if(func_021F1060(O)==10){
    if(p[40]==0){
failure:func_021EFC1C(p,3);func_021F1704(M,8,func_02012FFC());
fail_tail:func_021F1028(O);W(32)=28;
    }else {func_021F1704(M,38,func_02012FFC());func_021F1B24(M,1);W(32)=26;}
   }
  }break;
 case 20:func_021EFD24(p);W(32)=21;p[36]=9;break;
 case 21:func_021EFE40(p);break;
 case 22:
  func_021EFE3C(p);
  if(p[40]==0){func_021F1704(M,7,func_02012FFC());W(32)=23;}
  else {func_021F1704(M,39,func_02012FFC());func_021F1B24(M,1);W(32)=27;}break;
 case 23:
  if(func_021F1B14(M)==1) {u16 cnt=func_02007774((void *)GAME_DATA_GetBoxManager(SAVE));if(func_021F11F0(O,5,cnt)==1){func_021F1704(M,11,func_02012FFC());W(32)=24;}}break;
 case 24:
  if(func_021F1060(O)==2){func_021F1064(O);W(32)=14;}
  else if(func_021F1060(O)==9 || func_021F1060(O)==10){
   if(func_021F1060(O)==10)func_021EFC1C(p,3);
   func_021F1704(M,8,func_02012FFC());W(32)=27;
  }break;
 case 27:if(func_021F11F0(O,18,0)!=1)break;goto fail_tail;
 case 28:if(func_021F1B14(M)==1 && func_021F1040(O)==1){func_021F0FE8(O);W(32)=29;}break;
 case 29:if(func_021F1010(O)==1){if(p[40]==0)W(32)=2;else W(32)=25;}break;
 case 25:
  if(func_021F1B14(M)==1){func_021F1898(M);func_021F1628(M,1);func_021F1704(M,35,func_02012FFC());func_021F1B24(M,1);W(32)=26;}break;
 case 26:if(func_021F1010(O)==1 && func_021F1B14(M)==1)W(32)=2;break;
 case 30:func_021F1704(M,10,func_02012FFC());func_021F1B24(M,1);W(32)=31;func_021F0FE8(O);break;
 case 31:if(func_021F1B14(M)==1)W(32)=29;
 case 32:func_021EFFB0(p);break;
 case 33:if(func_021F1B14(M)==1)W(32)=2;break;
 }
 CLACT_DrawSystem(func_021F15B0(M));return 0;
}
