/* Copyright 2014-2016 Samsung Electronics Co., Ltd.
 * Copyright 2016 University of Szeged.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * Pool manager interface
 */
#ifndef MEM_POOLMAN_H
#define MEM_POOLMAN_H

#include "jrt.h"

/** \addtogroup mem Memory allocation
 * @{
 *
 * \addtogroup poolman Memory pool manager
 * @{
 */

extern void mem_pools_init (void);
extern void mem_pools_finalize (void);
extern void *mem_pools_alloc (void);
extern void mem_pools_free (void *);
extern void mem_pools_collect_empty (void);

#ifdef MEM_STATS
/**
 * Pools' memory usage statistics
 */
typedef struct
{
  /** pools' count */
  size_t pools_count;

  /** peak pools' count */
  size_t peak_pools_count;

  /** non-resettable peak pools' count */
  size_t global_peak_pools_count;

  /** free chunks count */
  size_t free_chunks;

  /* Number of newly allocated pool chunks */
  size_t new_alloc_count;

  /* Number of reused pool chunks */
  size_t reused_count;
} mem_pools_stats_t;

extern void mem_pools_get_stats (mem_pools_stats_t *);
extern void mem_pools_stats_reset_peak (void);
extern void mem_pools_stats_print (void);
#endif /* MEM_STATS */

/**
 * @}
 * @}
 */

#endif /* !MEM_POOLMAN_H */
