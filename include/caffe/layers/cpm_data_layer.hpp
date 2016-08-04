#ifndef CPM_DATA_LAYER_HPP_
#define CPM_DATA_LAYER_HPP_

#include <string>
#include <utility>
#include <vector>

#include "caffe/blob.hpp"
#include "caffe/data_transformer.hpp"
#include "caffe/internal_thread.hpp"
#include "caffe/layer.hpp"
#include "caffe/layers/base_data_layer.hpp"
#include "caffe/proto/caffe.pb.h"
#include "caffe/data_reader.hpp"
namespace caffe {


template <typename Dtype>
class CPMDataLayer : public BasePrefetchingDataLayer<Dtype> {
  public:
    explicit CPMDataLayer(const LayerParameter& param);
    virtual ~CPMDataLayer();
    virtual void DataLayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
    virtual inline bool ShareInParallel() const { return false; }
    virtual inline const char* type() const { return "CPMData"; }
    virtual inline int ExactNumBottomBlobs() const { return 0; }
    virtual inline int MinTopBlobs() const { return 1; }
    virtual inline int MaxTopBlobs() const { return 2; }

  protected:
    virtual void load_batch(Batch<Dtype>* batch);
    //void generateLabelMap();

    DataReader reader_;
    Blob<Dtype> transformed_label_; // add another blob
    //Blob<Dtype> transformed_label_all_; // all peaks, including others
};

}  // namespace caffe

#endif 