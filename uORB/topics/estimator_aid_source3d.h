#ifdef __cplusplus
struct __EXPORT estimator_aid_source3d_s {
#else
struct estimator_aid_source3d_s {
#endif
       uint64_t timestamp;
       uint64_t timestamp_sample;
       uint8_t estimator_instance;
       uint32_t device_id;

       uint64_t time_last_fuse;

       float observation[3];
       float observation_variance[3];

       float innovation[3];
       float innovation_variance[3];
       float test_ratio[3];

       bool innovation_rejected;     // true if the observation has been rejected
       bool fused;                   // true if the sample was successfully fused
 
#ifdef __cplusplus
 
#endif
};
 
/* register this as object request broker structure */
//ORB_DECLARE(estimatorAidSource3d_s);
