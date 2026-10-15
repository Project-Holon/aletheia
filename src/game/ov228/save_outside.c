/*
 * file:     save_outside.c
 * unit:     yes
 * function: SAVE_OUTSIDE_Load, SAVE_OUTSIDE_Free, SAVE_OUTSIDE_Prepare, SAVE_OUTSIDE_WriteAsync, SAVE_OUTSIDE_IsLoaded, SAVE_OUTSIDE_IsCorrupt, SAVE_OUTSIDE_GetPayload, SAVE_OUTSIDE_CopyPayload, SAVE_OUTSIDE_ClearFlash
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
 * ov228 "save outside": the work object is a 0x380-byte flash save block
 * (magic 0xA10F49AE, counter at +4, CRC at +8 over +0xC..0x374). SAVE_OUTSIDE_Load
 * reads both flash copies (0x7F800, 0x7FC00) and keeps the newer valid one;
 * SAVE_OUTSIDE_WriteAsync runs the asynchronous write of the chosen copy.
 *
 * arity: BACKUP_SYSTEM_WriteFlash overwrites its incoming r3 from a global
 *   before forwarding, so the caller passes only r0-r2.
 * trailing: after the 68-byte SAVE_OUTSIDE_ClearFlash come zero padding, the
 *   save_outside.c string, then zeros through 0x021DFF80; no follower.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   BACKUP_SYSTEM_ReadFlash  0x020334CC  arm
 *   GF_STANDARD_SetupCalc  0x0203F1FC  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021DFF60     0x021DFF60  data a1
 *   BACKUP_SYSTEM_WriteFlashAsync  0x02033494  arm
 *   BACKUP_SYSTEM_CheckFlashAsync  0x020334B0  arm
 *   func_020071CC 0x020071CC thumb
 *   MYSTERY_DATA_DecryptBuffer 0x0200A50C thumb
 *   MYSTERY_DATA_EncryptBuffer 0x0200A4B8 thumb
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 *   func_02082A7C 0x02082A7C arm
 *   BACKUP_SYSTEM_WriteFlash 0x02033478 arm
 */

struct HeapManager;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

/* 0xCC-byte payload chunk (three of them follow the 256-byte head) */
struct SaveOutsideChunk { u32 w[51]; };

/* the ov228 flash save work object (0x380 bytes) */
typedef struct {
    u32 magic;             /* 0x000 0xA10F49AE */
    u32 counter;           /* 0x004 save generation, newer wins */
    u16 crc;               /* 0x008 CRC over 0x00C..0x374 */
    u8 payload[0x368];     /* 0x00C */
    u32 state;             /* 0x374 0 ok, 1..3 the load outcome */
    u8 loaded;             /* 0x378 1 once a copy was loaded */
    u8 phase;              /* 0x379 async write step */
    u8 copyIndex;          /* 0x37A which flash copy is being written */
    u8 pad37B;             /* 0x37B padding, never read */
    u16 token;             /* 0x37C BACKUP_SYSTEM_WriteFlashAsync token */
    u16 pad37E;            /* 0x37E padding, never read */
} SaveOutsideWork;

extern void *func_02030734(u32 heap,u32 size,int clear,const char *site,u16 tag);
extern int BACKUP_SYSTEM_ReadFlash(u32 a, u32 b, u32 c);
extern u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len);
extern void MI_CpuCopy8(const void *src,void *dest,u32 size);
extern u32 func_020307B0(void *p);
extern u16 BACKUP_SYSTEM_WriteFlashAsync(u32, void *, u32);
extern int BACKUP_SYSTEM_CheckFlashAsync(u16, u16 *);
extern void *func_020071CC(struct HeapManager *ctrl, u32 id);
extern void MYSTERY_DATA_DecryptBuffer(void *base, u32 kind);
extern void MYSTERY_DATA_EncryptBuffer(void *base, u32 kind);
extern void func_02082A7C(u32 data,void *dest,u32 size);
extern void BACKUP_SYSTEM_WriteFlash(int a,int b,int c);
void *SAVE_OUTSIDE_Load(u32 heap);
void SAVE_OUTSIDE_Free(void *p);
void SAVE_OUTSIDE_Prepare(SaveOutsideWork *work);
int SAVE_OUTSIDE_WriteAsync(SaveOutsideWork *work);
u8 SAVE_OUTSIDE_IsLoaded(SaveOutsideWork *work);
int SAVE_OUTSIDE_IsCorrupt(SaveOutsideWork *work);
void *SAVE_OUTSIDE_GetPayload(SaveOutsideWork *work);
void SAVE_OUTSIDE_CopyPayload(SaveOutsideWork *work, void *ctrl);
void SAVE_OUTSIDE_ClearFlash(u32 heap);
extern const char d_021DFF60[];



/*
 * ov228 entry: allocate the 0x380-byte work object and a 0x374-byte scratch,
 * read both flash copies (0x7F800, 0x7FC00), check the magic and the CRC over
 * +0xC..0x374, pick the newer valid copy by the +4 counter (0 after
 * 0xFFFFFFFF counts as older), record the outcome at +0x374 and the loaded
 * flag at +0x378, free the scratch, return the object. Stack slots follow
 * declaration order in reverse: copies/readOk/crcBad arrays and then
 * work/chosen must be declared in this order.
 */
void *SAVE_OUTSIDE_Load(u32 heap)
{
    u8 *copies[2];
    int readOk[2];
    int crcBad[2];
    SaveOutsideWork *work;
    int chosen;
    u8 *copy;
    int idx;

    chosen=-1;
    work=(SaveOutsideWork *)func_02030734(heap,0x380,1,d_021DFF60,0x5b);
    copies[0]=(u8 *)work;
    copies[1]=func_02030734(heap,0x374,1,d_021DFF60,0x5d);
    for(idx=0;idx<2;idx++){
        readOk[idx]=0;
        crcBad[idx]=0;
    }
    readOk[0]=BACKUP_SYSTEM_ReadFlash(0x7F800,(u32)copies[0],0x374);
    readOk[1]=BACKUP_SYSTEM_ReadFlash(0x7FC00,(u32)copies[1],0x374);
    for(idx=0;idx<2;idx++){
        if(readOk[idx]==1){
            copy=copies[idx];
            if(((SaveOutsideWork *)copy)->magic!=0xA10F49AE)readOk[idx]=0;
            else if(((SaveOutsideWork *)copy)->crc!=GF_STANDARD_SetupCalc(copy+12,0x368))crcBad[idx]=1;
        }
    }
    work->loaded=0;
    if(readOk[0]==0&&readOk[1]==0){
    }else if(readOk[0]==1&&readOk[1]==0){
        if(crcBad[0]==1)work->state=3;
        else chosen=0;
    }else if(readOk[0]==0&&readOk[1]==1){
        if(crcBad[1]==1)work->state=3;
        else chosen=1;
    }else if(readOk[0]==1&&readOk[1]==1){
        if(crcBad[0]==1&&crcBad[1]==1)work->state=3;
        else if(crcBad[0]==0&&crcBad[1]==0){
            if(((SaveOutsideWork *)copies[0])->counter>=((SaveOutsideWork *)copies[1])->counter||(((SaveOutsideWork *)copies[0])->counter==0&&((SaveOutsideWork *)copies[1])->counter==0xFFFFFFFF))chosen=0;
            else chosen=1;
        }else if(crcBad[0]==0){
            work->state=2;
            chosen=0;
        }else{
            chosen=1;
            work->state=1;
        }
    }
    if(chosen==1)MI_CpuCopy8(copies[1],copies[0],0x374);
    func_020307B0(copies[1]);
    if(chosen!=-1)work->loaded=1;
    return work;
}



/*
 * Unlabelled leaf in ov228 (it saves nothing; the listing prints it as
 * .word data after pool_021DFDB4): a one-argument forwarding tail call to
 * the heap free func_020307B0, `ldr r3, [pc]; bx r3` plus the pool word.
 * Its caller is arm9 MYSTERY_DATA_Unload (mystery_data.c), whose MATCH park
 * names this address as its only unwitnessed call.
 */
void SAVE_OUTSIDE_Free(void *p)
{
    func_020307B0(p);
}


/*
 * Prepare the work object for a write: clear the phase, select the flash copy
 * from the load outcome at +0x374, refresh the magic, bump the counter and
 * recompute the CRC. (arity: the original stores live r0 after GF_STANDARD_SetupCalc
 * despite its legacy void return; the returned low halfword is kept.)
 */
void SAVE_OUTSIDE_Prepare(SaveOutsideWork *work)
{
    work->phase=0;
    if(work->state==2)work->copyIndex=1;
    else work->copyIndex=0;
    work->magic=0xA10F49AE;
    work->counter+=1;
    work->crc=GF_STANDARD_SetupCalc((u8 *)work+12,0x368);
}



/*
 * Async flash write state machine: step 0/2 start the write of the selected
 * copy and step 1/3 poll it, flipping the copy on each pass; the default step
 * clears the state and marks the object loaded.
 * (BACKUP_SYSTEM_WriteFlashAsync/CheckFlashAsync are ARM tail-call accessors
 * that save no lr, so sole-ref/code cannot see them; they are attested by
 * their matched addresses 0x02033494 and 0x020334B0.)
 */
int SAVE_OUTSIDE_WriteAsync(SaveOutsideWork *work)
{
    u16 v;

    switch (work->phase) {
    case 0:
    case 2:
        work->token =
            BACKUP_SYSTEM_WriteFlashAsync(work->copyIndex == 0 ? 0x7F800 : 0x7FC00, work, 0x374);
        work->phase = work->phase + 1;
        break;
    case 1:
    case 3:
        if (BACKUP_SYSTEM_CheckFlashAsync(work->token, &v) == 1) {
            work->copyIndex = work->copyIndex ^ 1;
            work->phase = work->phase + 1;
        }
        break;
    default:
        work->state = 0;
        work->loaded = 1;
        return 1;
    }
    return 0;
}



/*
 * Unlabelled leaf in ov228: returns the byte at +0x378 of the work object
 * (0x378 built as 0xDE << 2). Caller: arm9 MYSTERY_DATA_Load
 * (mystery_data.c).
 */
u8 SAVE_OUTSIDE_IsLoaded(SaveOutsideWork *work)
{
    return work->loaded;
}



int SAVE_OUTSIDE_IsCorrupt(SaveOutsideWork *work)
{
    if (work->state == 3)
        return 1;
    return 0;
}



void *SAVE_OUTSIDE_GetPayload(SaveOutsideWork *work)
{
    return (u8 *)work + 0xc;
}



void SAVE_OUTSIDE_CopyPayload(SaveOutsideWork *work, void *ctrl)
{
    u8 *buf;
    u8 *src;
    int i;
    int j;
    buf = func_020071CC(ctrl, 0x22);
    src = (u8 *)work + 0xC;
    MYSTERY_DATA_DecryptBuffer(buf, 1);
    MYSTERY_DATA_DecryptBuffer(src, 0);
    for (i = 0; i < 256; i++)
        buf[i] = src[i];
    for (j = 0; j < 3; j++)
        *(struct SaveOutsideChunk *)(buf + 0x100 + j * 0xCC) = *(struct SaveOutsideChunk *)(src + 0x100 + j * 0xCC);
    MYSTERY_DATA_EncryptBuffer(buf, 1);
    MYSTERY_DATA_EncryptBuffer(src, 0);
}


/*
 * Write 0xFF over the first flash copy (0x7F800, 2048 bytes).
 */
void SAVE_OUTSIDE_ClearFlash(u32 heap)
{
    void *p;
    p=func_02030734(heap,2048,0,d_021DFF60,339);
    func_02082A7C(0xFFFFFFFF,p,2048);
    BACKUP_SYSTEM_WriteFlash(0x7F800,(int)p,2048);
    func_020307B0(p);
}
