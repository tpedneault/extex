#ifndef RENDER_JOBS_H
#define RENDER_JOBS_H

#include "types.hpp"

/**
 * @enum RENDER_JOB_STATE
 * @brief Enumerates the possible states of a rendering job.
 */
enum RENDER_JOB_STATE {
  QUEUED,    ///< Job is queued and waiting to be executed.
  RUNNING,   ///< Job is currently being executed.
  COMPLETED, ///< Job has completed execution successfully.
  FAILED     ///< Job has failed to complete successfully.
};

/**
 * @enum RENDER_JOB_PRIORITY
 * @brief Enumerates the priority levels of rendering jobs.
 */
enum RENDER_JOB_PRIORITY {
  HIGH,   ///< High priority, should be executed before normal and low priority
          ///< jobs.
  NORMAL, ///< Normal priority, default priority level.
  LOW     ///< Low priority, executed after high and normal priority jobs.
};

/**
 * @class RenderingJob
 * @brief Abstract base class for all rendering jobs.
 *
 * Defines the interface and common functionality for rendering jobs.
 * Each job has a unique identifier, a state, and a priority level.
 */
class RenderingJob {
public:
  /**
   * @brief Virtual destructor.
   *
   * Ensures derived classes can be properly cleaned up when deleted.
   */
  virtual ~RenderingJob() = default;

  /**
   * @brief Executes the rendering job.
   * @return STATUS indicating the success or failure of the job execution.
   *
   * Pure virtual function that must be implemented by derived classes
   * to define specific rendering logic.
   */
  virtual STATUS Execute() = 0;

protected:
  /**
   * @brief Protected constructor for RenderingJob.
   * @param id Unique identifier for the rendering job.
   * @param priority Priority level of the job (defaults to NORMAL).
   *
   * Initializes a rendering job with the given ID and priority.
   */
  RenderingJob(CSTR id, RENDER_JOB_PRIORITY priority = NORMAL);

  CSTR m_ID;                ///< Unique identifier for the rendering job.
  RENDER_JOB_STATE m_state; ///< Current state of the rendering job.
  RENDER_JOB_PRIORITY m_priority; ///< Priority level of the rendering job.
};

class TextRenderingJob : public RenderingJob {
public:
  UINT32 test;
};

class ModelRenderingJob : public RenderingJob {
public:
  UINT32 test;

private:
};

#endif /* RENDER_JOBS_H */
