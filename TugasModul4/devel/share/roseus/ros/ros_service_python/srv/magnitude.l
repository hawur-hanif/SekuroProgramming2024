;; Auto-generated. Do not edit!


(when (boundp 'ros_service_python::magnitude)
  (if (not (find-package "ROS_SERVICE_PYTHON"))
    (make-package "ROS_SERVICE_PYTHON"))
  (shadow 'magnitude (find-package "ROS_SERVICE_PYTHON")))
(unless (find-package "ROS_SERVICE_PYTHON::MAGNITUDE")
  (make-package "ROS_SERVICE_PYTHON::MAGNITUDE"))
(unless (find-package "ROS_SERVICE_PYTHON::MAGNITUDEREQUEST")
  (make-package "ROS_SERVICE_PYTHON::MAGNITUDEREQUEST"))
(unless (find-package "ROS_SERVICE_PYTHON::MAGNITUDERESPONSE")
  (make-package "ROS_SERVICE_PYTHON::MAGNITUDERESPONSE"))

(in-package "ROS")





(defclass ros_service_python::magnitudeRequest
  :super ros::object
  :slots (_komponenX _komponenY _komponenZ ))

(defmethod ros_service_python::magnitudeRequest
  (:init
   (&key
    ((:komponenX __komponenX) 0.0)
    ((:komponenY __komponenY) 0.0)
    ((:komponenZ __komponenZ) 0.0)
    )
   (send-super :init)
   (setq _komponenX (float __komponenX))
   (setq _komponenY (float __komponenY))
   (setq _komponenZ (float __komponenZ))
   self)
  (:komponenX
   (&optional __komponenX)
   (if __komponenX (setq _komponenX __komponenX)) _komponenX)
  (:komponenY
   (&optional __komponenY)
   (if __komponenY (setq _komponenY __komponenY)) _komponenY)
  (:komponenZ
   (&optional __komponenZ)
   (if __komponenZ (setq _komponenZ __komponenZ)) _komponenZ)
  (:serialization-length
   ()
   (+
    ;; float64 _komponenX
    8
    ;; float64 _komponenY
    8
    ;; float64 _komponenZ
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _komponenX
       (sys::poke _komponenX (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _komponenY
       (sys::poke _komponenY (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _komponenZ
       (sys::poke _komponenZ (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _komponenX
     (setq _komponenX (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _komponenY
     (setq _komponenY (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _komponenZ
     (setq _komponenZ (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass ros_service_python::magnitudeResponse
  :super ros::object
  :slots (_magnitude ))

(defmethod ros_service_python::magnitudeResponse
  (:init
   (&key
    ((:magnitude __magnitude) 0.0)
    )
   (send-super :init)
   (setq _magnitude (float __magnitude))
   self)
  (:magnitude
   (&optional __magnitude)
   (if __magnitude (setq _magnitude __magnitude)) _magnitude)
  (:serialization-length
   ()
   (+
    ;; float64 _magnitude
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _magnitude
       (sys::poke _magnitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _magnitude
     (setq _magnitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass ros_service_python::magnitude
  :super ros::object
  :slots ())

(setf (get ros_service_python::magnitude :md5sum-) "55d1a215f43fd1f64eb105a505b172c4")
(setf (get ros_service_python::magnitude :datatype-) "ros_service_python/magnitude")
(setf (get ros_service_python::magnitude :request) ros_service_python::magnitudeRequest)
(setf (get ros_service_python::magnitude :response) ros_service_python::magnitudeResponse)

(defmethod ros_service_python::magnitudeRequest
  (:response () (instance ros_service_python::magnitudeResponse :init)))

(setf (get ros_service_python::magnitudeRequest :md5sum-) "55d1a215f43fd1f64eb105a505b172c4")
(setf (get ros_service_python::magnitudeRequest :datatype-) "ros_service_python/magnitudeRequest")
(setf (get ros_service_python::magnitudeRequest :definition-)
      "float64 komponenX
float64 komponenY
float64 komponenZ
---
float64 magnitude
")

(setf (get ros_service_python::magnitudeResponse :md5sum-) "55d1a215f43fd1f64eb105a505b172c4")
(setf (get ros_service_python::magnitudeResponse :datatype-) "ros_service_python/magnitudeResponse")
(setf (get ros_service_python::magnitudeResponse :definition-)
      "float64 komponenX
float64 komponenY
float64 komponenZ
---
float64 magnitude
")



(provide :ros_service_python/magnitude "55d1a215f43fd1f64eb105a505b172c4")


