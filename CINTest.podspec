Pod::Spec.new do |spec|

  spec.name         = "CINTest"
  spec.version      = "1.0.2"
  spec.summary      = "A test pod"

  spec.description  = <<-DESC
			A test pod project, only include frameworks
                   DESC

  spec.homepage     = "https://github.com/cinRiggers/CINTest"
  
  spec.author       =  "Riggers"
  spec.source       = { :git => "https://github.com/cinRiggers/CINTest.git", :tag => "#{spec.version}" }
  spec.ios.deployment_target = "9.2"
  
  spec.static_framework = false
  spec.requires_arc = true
  spec.pod_target_xcconfig =   {'ENABLE_BITCODE' => 'NO'} 
  
  # spec.dependency 'CINRTC','~>1.0.0'
  # spec.dependency 'CINWebRTC','~>1.0.0'

  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }
  spec.vendored_frameworks = 'Framework/CINSIP.framework' 

end
