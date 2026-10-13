/*
 * function: DSPi_FileIOProc
 * address:  0x027067B4
 * packet:   pkt_027067B4
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libdsp dsp_process.o (hidden function between DSP_StoreData and
 * DSPi_NotifyFileIOUpdation).  Thread procedure that serves the DSP side's file requests:
 * it waits for a request bit, loads the file's two pipes and runs the
 * commands (open, close, seek, read, write, open from memory) that arrive
 * on the pipe.  Never returns.
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02085E50  0x02085E50  arm
 *   DSP_LoadPipe  0x02706D44  arm
 *   DSP_GetPipeReadableSize  0x02706E90  arm
 *   DSP_ReadPipe  0x02706EC0  arm
 *   DSP_WritePipe  0x02706FCC  arm
 *   func_020789FC  0x020789FC  arm
 *   func_02078A80  0x02078A80  arm
 *   func_02078A94  0x02078A94  arm
 *   func_02078AEC  0x02078AEC  arm
 *   func_02078B44  0x02078B44  arm
 *   func_02078B70  0x02078B70  arm
 *   func_02078BC4  0x02078BC4  arm
 *   func_0207A940  0x0207A940  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
typedef int BOOL;

typedef struct FSFile {
    struct FSFile *next;
    void *userdata;
    void *arc;
    u32 stat;
    void *argument;
    int error;
    void *queue[2];
    u8 prop[16];
    u8 arg[24];
} FSFile;

static inline BOOL FS_IsFile(FSFile *f)
{
    return (f->stat & 0x10) ? 1 : 0;
}

typedef struct DSPPipe {
    u16 w[5];
} DSPPipe;

typedef struct DSPProcess {
    u8 pad0[0xC8];
    u8 msgQueue[0x20];
    u32 fileRequest;
    FSFile file[8];
} DSPProcess;

extern u32 func_02087988(void);
extern void func_0208799C(u32 state);
extern BOOL func_02085E50(void *queue, void *msg, s32 flags);
extern void DSP_LoadPipe(DSPPipe *pipe, int port, int dir);
extern u32 DSP_GetPipeReadableSize(DSPPipe *pipe);
extern void DSP_ReadPipe(DSPPipe *pipe, void *buf, u32 len);
extern void DSP_WritePipe(DSPPipe *pipe, void *buf, u32 len);
extern BOOL func_020789FC(FSFile *file, const char *path, u32 mode);
extern void func_02078A80(FSFile *file);
extern u32 func_02078A94(FSFile *file);
extern u32 func_02078AEC(FSFile *file);
extern BOOL func_02078B44(FSFile *file, long offset, int origin);
extern s32 func_02078B70(FSFile *file, void *dst, s32 len);
extern s32 func_02078BC4(FSFile *file, const void *src, s32 len);
extern BOOL func_0207A940(FSFile *file, void *buf, u32 size);

void DSPi_FileIOProc(DSPProcess *p)
{
    u8 path[0x108];
    u8 rbuf[0x100];
    u8 wbuf[0x100];
    DSPPipe in;
    DSPPipe out;
    u32 msg[1];
    u32 readA;
    u32 readB;
    u32 seekPos;
    u32 seekOut;
    u16 cmd;
    u16 openMode;
    u16 pathLen;
    u16 openRes;
    u16 memRes;
    u16 closeRes;
    u16 seekMode;
    u16 readLen;
    u16 readHalf;
    u16 writeLen;
    u32 state;
    u32 bits;
    int index;
    FSFile *file;

    for (;;) {
        state = func_02087988();
        for (;;) {
            bits = p->fileRequest;
            bits = ~bits & (bits - 1);
            asm { clz bits, bits }
            index = 32 - bits;
            if (index < 8) {
                break;
            }
            func_02085E50(p->msgQueue, msg, 1);
        }
        p->fileRequest &= ~(1 << index);
        func_0208799C(state);
        file = &p->file[index];
        DSP_LoadPipe(&in, index, 0);
        DSP_LoadPipe(&out, index, 1);

        while (DSP_GetPipeReadableSize(&in) >= 2) {
            DSP_ReadPipe(&in, &cmd, 2);
            switch (cmd) {
            case 0:
                DSP_ReadPipe(&in, &openMode, 2);
                DSP_ReadPipe(&in, &pathLen, 2);
                pathLen = pathLen * 2;
                DSP_ReadPipe(&in, path, pathLen);
                path[pathLen] = 0;
                func_020789FC(file, (const char *)path, openMode);
                openRes = FS_IsFile(file) ? 1 : 0;
                DSP_WritePipe(&out, &openRes, 2);
                break;
            case 5:
                DSP_ReadPipe(&in, &readA, 4);
                DSP_ReadPipe(&in, &readB, 4);
                readA = (readA >> 16) | (readA << 16);
                readB = ((readB >> 16) | (readB << 16)) << 1;
                func_0207A940(file, (void *)readA, readB);
                memRes = FS_IsFile(file) ? 1 : 0;
                DSP_WritePipe(&out, &memRes, 2);
                break;
            case 1:
                func_02078A80(file);
                closeRes = 1;
                DSP_WritePipe(&out, &closeRes, 2);
                break;
            case 2:
                DSP_ReadPipe(&in, &seekPos, 4);
                DSP_ReadPipe(&in, &seekMode, 2);
                seekPos = (seekPos >> 16) | (seekPos << 16);
                func_02078B44(file, seekPos, seekMode);
                seekOut = func_02078AEC(file);
                seekOut = (seekOut >> 16) | (seekOut << 16);
                DSP_WritePipe(&out, &seekOut, 4);
                break;
            case 3:
                DSP_ReadPipe(&in, &readLen, 2);
                readLen = readLen << 1;
                {
                    u32 rest = func_02078A94(file) - func_02078AEC(file);
                    u32 t = readLen;
                    if (t > rest) {
                        t = rest;
                    }
                    readLen = t;
                }
                readHalf = readLen >> 1;
                DSP_WritePipe(&out, &readHalf, 2);
                while (readLen != 0) {
                    u16 n = readLen > 0x100 ? 0x100 : readLen;
                    func_02078B70(file, rbuf, n);
                    DSP_WritePipe(&out, rbuf, n);
                    readLen = readLen - n;
                }
                break;
            case 4:
                DSP_ReadPipe(&in, &writeLen, 2);
                writeLen = writeLen << 1;
                while (writeLen != 0) {
                    u16 n = writeLen > 0x100 ? 0x100 : writeLen;
                    DSP_ReadPipe(&in, wbuf, n);
                    func_02078BC4(file, wbuf, n);
                    writeLen = writeLen - n;
                }
                break;
            }
        }
    }
}
