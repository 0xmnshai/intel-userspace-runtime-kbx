#include "kbx_io_v4l2.h"
#include <cstdio>
#include <cstdlib>

#include <linux/videodev2.h>

int main(int argc, char **argv) {
  if (argc < 5) {
    fprintf(stderr, "usage: %s <device> <width> <height> <count>\n", argv[0]);
    exit(1);
  }

  kbx_v4l2_device device;
  const char *device_name = argv[1];
  int width = atoi(argv[2]);
  int height = atoi(argv[3]);
  int count = atoi(argv[4]);
  (void)count; // To be used for stream control logic later

  kbx_v4l2_init_params_t params;
  params.device_name = (char *)device_name;
  params.width = width;
  params.height = height;
  params.format = V4L2_PIX_FMT_UYVY;
  params.interval = 1;
  params.io_type = V4L2_MEMORY_DMABUF;
  params.frame_count = count;

  kbx_v4l2_init(&device, &params);
  kbx_v4l2_start_capture(&device, &params);
}