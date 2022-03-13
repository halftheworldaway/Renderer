#version 330 core
out vec4 FragColor;

in vec3 Normal;  
in vec3 FragPos;  
  
uniform vec3 lightPos; 
uniform vec3 lightColor;
uniform vec3 objectColor;
uniform vec3 viewpos;

void main()
{
    // ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
   
    //specular
    float specular_strength = 0.5;
    vec3 viewdir = normalize(viewpos - FragPos);
    vec3 reflectdir = normalize(reflect(-lightDir, norm));
    float spec = pow(max(dot(viewdir, reflectdir), 0.0f), 32);

    vec3 result = (ambient + diffuse + spec) * objectColor;
    FragColor = vec4(result, 1.0);

} 