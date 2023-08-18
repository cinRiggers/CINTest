Pod::Spec.new do |spec|

  spec.name         = "CINTest"
  spec.version      = "1.0.1"
  spec.summary      = "A test pod"

  spec.description  = <<-DESC
			A test pod project, only include frameworks
                   DESC

  spec.homepage     = "https://github.com/cinRiggers/CINTest"
  
  spec.author       =  "Riggers"
  spec.source       = { :git => "https://github.com/cinRiggers/CINTest.git", :tag => "#{spec.version}" }
  spec.ios.deployment_target = "11.0"
  
  spec.static_framework = false
  spec.requires_arc = true
  spec.pod_target_xcconfig =   {'ENABLE_BITCODE' => 'NO'} 

  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }
  spec.vendored_frameworks = 'Framework/CINRTC.framework' 
  spec.vendored_frameworks = 'Framework/WebRTC.framework' 
  spec.vendored_frameworks = 'Framework/CINSIP.framework' 

end
