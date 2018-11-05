#!/usr/bin/env python
# -*- coding: utf-8 -*-
########################################################################
# 
# 
########################################################################
 
"""
File: custom_eval_metric.py
Author: lisongsong02
Date: 2018/10/10 17:29:27
"""
import numpy as np
import xgboost as xgb

def custom_obj(preds, dtrain):

    lables = dtrain.get_label()
    preds = 1.0 / (1.0 + np.exp(-preds))
    grad = preds - labels
    hess = preds * (1.0 - preds)
    return grad, hess

def custom_eval(preds, dtrain):

    labels = dtrain.get_label()
    return "self_define_name_error", fload(sum(labels!= (preds > 0.0))) / len(labels)


