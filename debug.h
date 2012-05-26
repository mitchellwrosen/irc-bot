#ifndef _DEBUG_H_
#define _DEBUG_H_

#define EXIT_IF(pred, msg); { \
  if (pred) { \
    fprintf(stderr, msg); \
    exit(EXIT_FAILURE); \
  } \
}

#endif  // _DEBUG_H_
