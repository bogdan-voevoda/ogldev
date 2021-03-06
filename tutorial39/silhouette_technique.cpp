/*

	Copyright 2011 Etay Meiri

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <limits.h>
#include <string>
#include <glfx.h>
#include <assert.h>

#include "silhouette_technique.h"
#include "util.h"

using namespace std;

static const char* pEffectFile = "shaders/silhouette.glsl";

SilhouetteTechnique::SilhouetteTechnique() : Technique(pEffectFile)
{   
}


bool SilhouetteTechnique::Init()
{
    if (!CompileProgram("Silhouette")) {
        return false;
    }
    
    m_WVPLocation = GetUniformLocation("gWVP");
    m_WorldMatrixLocation = GetUniformLocation("gWorld");
    m_lightPosLocation = GetUniformLocation("gLightPos");

    return true;
}


void SilhouetteTechnique::SetWVP(const Matrix4f& WVP)
{
    glUniformMatrix4fv(m_WVPLocation, 1, GL_TRUE, (const GLfloat*)WVP.m);    
}


void SilhouetteTechnique::SetWorldMatrix(const Matrix4f& WorldInverse)
{
    glUniformMatrix4fv(m_WorldMatrixLocation, 1, GL_TRUE, (const GLfloat*)WorldInverse.m);
}


void SilhouetteTechnique::SetLightPos(const Vector3f& Pos)
{
    glUniform3f(m_lightPosLocation, Pos.x, Pos.y, Pos.z);
}