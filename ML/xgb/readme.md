# xgboost

## 参数类型

###  通用参数

* booster[default:gbtree, gblinear]

* silent[default:0]

* nthread[default: all kernels]

### booster参数(调参)

* eta[0.01 ～ 0.3， default:0.3]

* min_child_weight[默认1] 最小的叶子结点权重之和

* max_depth[default:6]  max_leaf_nodes

* gamma[default:0] 损失函数下降的分裂阈值

* max_delta_step[0, 限制每棵树权重改变的最大步长]

* subsample[default:1] 行采样

* colsample_bytree[default 1] 列采样

* colsample_bylevel[default 1] 树的每一级的每一次分裂，对列数的采样的占比

* lambda, alpha[default:1] regularization

* scale_pos_weight[default:1] unbalanced data

###  学习目标参数

* objective[default reg:linear]

> binary:logistic 
> 
> multi:softmax multi:softprob

* eval_metric 

> rmse, mae
> 
> logloss, mlogloss
>
> error, merror
> 
> auc

* seed [default:0]

## 调参

* 选择较高的学习率，根据cv得到理想的决策树个数。

* 学习率与决策树个数确定后，调整booster参数。（max_depth, min_child_weight, gamma, subsample, colsample_bytree）

* 正则化(lambda alpha)

* 降低学习速率，在重复上述步骤。

PS: num_boosting_rounds 就是GBM的n_estimator


