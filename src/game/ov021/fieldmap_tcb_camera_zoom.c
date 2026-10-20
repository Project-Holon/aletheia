/*
 * file:     fieldmap_tcb_camera_zoom.c
 * unit:     yes
 * function: FIELDMAP_TCB_CAMERA_ZOOM_Create, FIELDMAP_TCB_CAMERA_ZOOM_Main, FIELDMAP_TCB_CAMERA_ZOOM_Step
 * address:  0x021C6B18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_g3dobj.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   TCB_DeleteTask  0x02030EAC  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetTcblSys  0x02188D30  thumb  ov021
 *   FIELD_CAMERA_GetDistance  0x0218ED54  thumb  ov021
 *   TCB_AddTask  0x02030DA8  arm
 *   gFieldmapTcbCameraZoomFileName     0x021DE4B8  data  ov021  a4
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb  ov021
 *   _ffix          0x0209C494  arm
 *   _dsqrt         0x0209C5E0  arm
 *   _f2d                         0x0209BD38  arm
 *   _fadd                        0x0209C95C  arm
 *   _fdiv                        0x0209CE10  arm
 *   _fflt                        0x0209BDBC  arm
 *   _ffltu                       0x0209BE04  arm
 *   _fgr                         0x0209BBB0  arm
 *   _fmul                        0x0209C77C  arm
 *   _fsub                        0x0209CB8C  arm
 */
#include "../types.h"

/* Field camera zoom task (021C6B18..021C6BB4)                          */

/* Task work (0x10 bytes). */
typedef struct CameraZoomWork {
    void *fieldMap;
    u16 frame;
    u16 frameMax;
    fx32 startZoom;
    fx32 endZoom;
} CameraZoomWork;
struct FieldMap;

#include "fieldmap.h"
struct FieldCamera;

struct TcbSystem;


#include "field_camera.h"


struct TcbTask;

#include "../arm9/tcb_list.h"

extern char gFieldmapTcbCameraZoomFileName[];   /* source file name used as allocation site */

extern double _dsqrt(double x);

void FIELDMAP_TCB_CAMERA_ZOOM_Create(void *fieldMap, u16 frames, fx32 zoomDelta);

void FIELDMAP_TCB_CAMERA_ZOOM_Main(void *task, CameraZoomWork *w);

void FIELDMAP_TCB_CAMERA_ZOOM_Step(CameraZoomWork *w);

#include "../arm9/gfl_heap_wrap.h"


void FIELDMAP_TCB_CAMERA_ZOOM_Create(void *fieldMap, u16 frames, fx32 zoomDelta)
{
    u32 heapId = FIELDMAP_GetHeapId(fieldMap);
    void *camera = FIELDMAP_GetCamera(fieldMap);
    u32 priority = (u32)FIELDMAP_GetTcblSys(fieldMap);
    CameraZoomWork *w;

    w = GFL_HEAP_Alloc((u16)((heapId & 0x7FFF) | 0x8000), sizeof(CameraZoomWork), 0, gFieldmapTcbCameraZoomFileName, 0x5F);
    w->frame = 0;
    w->frameMax = frames;
    w->startZoom = FIELD_CAMERA_GetDistance(camera);
    w->endZoom = zoomDelta + FIELD_CAMERA_GetDistance(camera);
    w->fieldMap = fieldMap;
    TCB_AddTask( (struct TcbSystem *)priority, (TcbFunc)FIELDMAP_TCB_CAMERA_ZOOM_Main, (void *)w, 0);
}

void FIELDMAP_TCB_CAMERA_ZOOM_Main(void *task, CameraZoomWork *w)
{
    FIELDMAP_TCB_CAMERA_ZOOM_Step(w);
    w->frame++;
    if (w->frameMax < w->frame) {
        GFL_HEAP_Free(w);
        TCB_DeleteTask(task);
    }
}

/*
 * Lever: `t = 1.0f; t *= a / b;` keeps the fmul by 1.0f; a plain `1.0f * x`
 * or `x * 1.0f` folds away. The FX32 round (x > 0 ? x*4096+0.5 : x*4096-0.5)
 * must go through one float temp so the _ffix and the call are shared.
 */
void FIELDMAP_TCB_CAMERA_ZOOM_Step(CameraZoomWork *w)
{
    void *camera = FIELDMAP_GetCamera(w->fieldMap);
    u32 frameMax = w->frameMax;
    float ratio, startZoom, endZoom, zoom;

    if (w->frame <= frameMax) {
        ratio = 1.0f;
        ratio *= (float)(u32)w->frame / (float)frameMax;
        ratio = (float)_dsqrt((double)ratio);
        startZoom = (float)w->startZoom / 4096.0f;
        endZoom = (float)w->endZoom / 4096.0f;
        zoom = (1.0f - ratio) * startZoom + ratio * endZoom;
        if (zoom > 0.0f)
            zoom = 4096.0f * zoom + 0.5f;
        else
            zoom = 4096.0f * zoom - 0.5f;
        FIELD_CAMERA_SetDistance(camera, (int)zoom);
    }
}
